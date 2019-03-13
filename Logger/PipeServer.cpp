#include "PipeServer.h"

#include <atlcomtime.h>

#include "PipeMessage.h"

#define PIPE_MAX_INSTANCES    (10)
#define  NAMED_PIPE_OUTPUT_BUFFER_SIZE  (40960)
#define  NAMED_PIPE_INPUT_BUFFER_SIZE   (0)

struct PipeInfo
{
  HANDLE hNamedPipe;
  HANDLE hRegWait;
  OVERLAPPED stOverlap;
  BOOL bConnected;

//   PipeInfo(void)
//     : hNamedPipe(nullptr),
//       hRegWait(nullptr),
//       bConnected(FALSE)
//   {
//   }
// 
//   PipeInfo(HANDLE hNamedPipeArg,
//            HANDLE hRegWaitArg,
//            OVERLAPPED stOverlapArg,
//            BOOL bConnectedArg)
//     : hNamedPipe(hNamedPipeArg),
//       hRegWait(hRegWaitArg),
//       stOverlap(stOverlapArg),
//       bConnected(bConnectedArg)
//   {
//   }
};

bool            CPipeLogServer::m_bDestroyed = FALSE;  
CPipeLogServer* CPipeLogServer::m_pInstance = NULL;

CPipeLogServer::CPipeLogServer(void)
  : m_hThread(nullptr)
{
}


CPipeLogServer::~CPipeLogServer(void)
{
  Finalize();

  m_bDestroyed = false;
}

CPipeLogServer* CPipeLogServer::GetInstance(void)
{
  if (m_bDestroyed)
  {
    m_pInstance = new CPipeLogServer();
    atexit(Kill);
    m_bDestroyed = false;
  }
  else if (nullptr == m_pInstance)
  {
    Create();
  }

  return m_pInstance;
}

void __stdcall OnWaitTimerCallback(PVOID lpParameter, BOOLEAN bTimerOrWaitFired)
{
  PipeInfo* pi = (PipeInfo *)lpParameter;
  pi->bConnected = TRUE;
}

BOOL CPipeLogServer::Initialize(const CString& strName)
{
  if (strName.IsEmpty())
    return FALSE;
  else
    m_strName = strName;

  BYTE sd[SECURITY_DESCRIPTOR_MIN_LENGTH];
  SECURITY_ATTRIBUTES stSA;

  stSA.nLength = sizeof(stSA);
  stSA.bInheritHandle = TRUE;
  stSA.lpSecurityDescriptor = &sd;

  InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
  SetSecurityDescriptorDacl(&sd, TRUE, (PACL)0, FALSE);

  CString strPipeName;
  strPipeName.Format(_T("\\\\.\\pipe\\%s"), strName);

  DWORD dwRet = ERROR_SUCCESS;
  PipeInfo* pPI = nullptr;

  for (int i=0; i<PIPE_MAX_INSTANCES; i++)
  {
    pPI = new PipeInfo;
    memset(pPI, 0, sizeof(PipeInfo));

    m_vecPipeInfo.push_back(pPI);

    pPI->hNamedPipe = CreateNamedPipe(strPipeName,
                                      PIPE_ACCESS_OUTBOUND | FILE_FLAG_OVERLAPPED,
                                      PIPE_TYPE_MESSAGE,
                                      PIPE_MAX_INSTANCES,
                                      NAMED_PIPE_OUTPUT_BUFFER_SIZE,
                                      NAMED_PIPE_INPUT_BUFFER_SIZE,
                                      NMPWAIT_USE_DEFAULT_WAIT,
                                      &stSA);
    if (INVALID_HANDLE_VALUE == pPI->hNamedPipe)
    {
      dwRet = GetLastError();
      break;
    }

    pPI->stOverlap.hEvent = ::CreateEvent(nullptr, FALSE, FALSE, nullptr);
    if (nullptr == pPI->stOverlap.hEvent)
    {
      dwRet = GetLastError();
      break;
    }

    if (!::RegisterWaitForSingleObject(&pPI->hRegWait,
                                       pPI->stOverlap.hEvent,
                                       OnWaitTimerCallback,
                                       pPI,
                                       INFINITE,
                                       WT_EXECUTEDEFAULT))
    {
      dwRet = GetLastError();
      break;
    }

    if (!ConnectNamedPipe(pPI->hNamedPipe, &pPI->stOverlap))
    {
      dwRet = GetLastError();
      switch (dwRet)
      {
      case ERROR_IO_PENDING:
      case ERROR_PIPE_CONNECTED:
        dwRet = ERROR_SUCCESS;
        break;
      }
    }
  }

  if (ERROR_SUCCESS != dwRet)
    return FALSE;
  else
    return nullptr != m_hThread;
}

void CPipeLogServer::Finalize()
{
  PipeInfo* pPI = nullptr;
  size_t count = m_vecPipeInfo.size();
  HANDLE hFinished;

  for (size_t i=0; i<count; i++)
  {
    pPI = (PipeInfo *)m_vecPipeInfo[i];

    if (nullptr != pPI->hRegWait)
    {
      hFinished = ::CreateEvent(nullptr, TRUE, FALSE, nullptr);
      if (nullptr != hFinished)
      {
        ::UnregisterWaitEx(pPI->hRegWait, hFinished);
        ::WaitForSingleObject(hFinished, IGNORE);
        ::CloseHandle(hFinished);
      }
      else
        ::UnregisterWait(pPI->hRegWait);
    }

    if (INVALID_HANDLE_VALUE != pPI->hNamedPipe)
    {
      CloseHandle(pPI->hNamedPipe);
      pPI->hNamedPipe = INVALID_HANDLE_VALUE;
    }

    if (pPI->stOverlap.hEvent)
      ::CloseHandle(pPI->stOverlap.hEvent);

    delete pPI;
  }

  m_vecPipeInfo.clear();
}

void CPipeLogServer::TransmitMessage(const CString& strLog)
{
  BOOL bRet = FALSE;
  ULONG ulProcessID = 0;
  PipeInfo* pPI = nullptr;
  size_t count = m_vecPipeInfo.size();
  
  CString strMessage;
  strMessage.Format(_T("[%s] %s"), 
                    COleDateTime::GetCurrentTime().Format(_T("%Y-%m-%d %H:%M:%S")), 
                    strLog);

  CPipeMessage msg;
  msg.SetData((void *)(LPCTSTR)strMessage, 
              (strMessage.GetLength() + 1) * sizeof(TCHAR));

  for (size_t i=0; i<count; i++)
  {
    pPI = (PipeInfo *)m_vecPipeInfo[i];

    if (INVALID_HANDLE_VALUE != pPI->hNamedPipe)
    {
      if (!msg.Write(pPI->hNamedPipe) && FALSE == pPI->bConnected)
      {
        bRet = DisconnectNamedPipe(pPI->hNamedPipe);
        bRet = ConnectNamedPipe(pPI->hNamedPipe, &pPI->stOverlap);
        if (FALSE == bRet || ERROR_IO_PENDING == GetLastError())
          msg.Write(pPI->hNamedPipe);
      }
    }
  }
}

void CPipeLogServer::TransmitMessage(LPCTSTR pszFormat, ...)
{
  va_list   ap;
  va_start(ap, pszFormat);
  
  //  set log message
  CString strMsg;
  strMsg.Format(_T("%s\n"), pszFormat);
  CString strLogMsg(strMsg);
  strLogMsg.FormatV((CString)strMsg, ap);
  va_end(ap);

  TransmitMessage(strLogMsg);
}

BOOL CPipeLogServer::IsConnected(void)
{
  BOOL bCheckConnected = FALSE;

  for (auto itor : m_vecPipeInfo)
  {
    PipeInfo* pi = (PipeInfo *)(itor);
    
    while (FALSE == bCheckConnected)
    {
      if (TRUE == pi->bConnected)
        bCheckConnected = TRUE;
    }

    break;
  }

  return TRUE;
}
