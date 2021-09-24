#include "StatusLog.h"

#include "../Utils/gSoap/soapProxy.h"
#include "../Utils/gSoap/Markisa.nsmap"

bool        CStatusLog::m_bDestroyed = FALSE;  
CStatusLog* CStatusLog::m_pInstance = NULL;

CStatusLog::CStatusLog(void)
  : m_strSoapAddress(_T(""))
  , m_strSoapIP(_T(""))
  , m_nSoapPort(0)
  , m_nConnectTimeout(0)
  , m_nAcceptTimeout(0)
  , m_nSendTimeout(0)
  , m_nRecvTimeout(0)
  , m_strAETitle(_T(""))
{
}


CStatusLog::~CStatusLog(void)
{
  m_bDestroyed = TRUE;
}

CStatusLog* CStatusLog::GetInstance(void)
{
  if (m_bDestroyed)
  {
    m_pInstance = new CStatusLog();
    //new(m_pInstance) CLogger(pszLogPrefixArg);
    atexit(KillLogger);
    m_bDestroyed = FALSE;
  }
  else if (NULL == m_pInstance)
  {
    Create();
  }

  return m_pInstance;
}

void CStatusLog::MakeSoapAddress(void)
{
  if (0 == m_strSoapIP.GetLength() || 0 == m_nSoapPort)
    return ;

  m_strSoapAddress.Format(_T("%s:%d"), m_strSoapIP, m_nSoapPort);
}

int CStatusLog::SendRecvStatus(const std::wstring& strCallingAETitle,
                               const std::wstring& strCalledAETitle, 
                               const int& nProcessing)
{
  if (false == m_bEnableStatus)
    return 0;

  int nRet = SOAP_ERR;
  Proxy p(SOAP_IO_KEEPALIVE, SOAP_IO_KEEPALIVE);
  CStringA strSoapAddress = CStringA(m_strSoapAddress);
  p.soap_endpoint = strSoapAddress;
  p.connect_timeout = m_nConnectTimeout;
  p.accept_timeout = m_nAcceptTimeout;
  p.send_timeout = m_nSendTimeout;
  p.recv_timeout = m_nRecvTimeout;

  struct wreq__WriteRequest stReqMsg;
  struct wres__WriteResponse stResMsg;

  stReqMsg.return_.strCallingAETtile = strCallingAETitle;
  stReqMsg.return_.strCalledAETitle = strCalledAETitle;
  stReqMsg.return_.nNumOfInstance = 0;
  stReqMsg.return_.eStatus = static_cast<Processing>(nProcessing);

  nRet = p.WriteRequest(stReqMsg, &stResMsg);

  return nRet;
}

int CStatusLog::SendRecvStatus(const std::wstring& strCallingAETitle, 
                               const std::wstring& strCalledAETitle, 
                               const std::wstring& strPatientID, 
                               const std::wstring& strPatientName, 
                               const std::wstring& strProtocol, 
                               const std::wstring& strSOPClassName, 
                               const int& nNumOfInstance)
{
  if (false == m_bEnableStatus)
    return 0;

  int nRet = SOAP_ERR;
  Proxy p(SOAP_IO_KEEPALIVE, SOAP_IO_KEEPALIVE);
  CStringA strSoapAddress = CStringA(m_strSoapAddress);
  p.soap_endpoint = strSoapAddress;
  p.connect_timeout = m_nConnectTimeout;
  p.accept_timeout = m_nAcceptTimeout;
  p.send_timeout = m_nSendTimeout;
  p.recv_timeout = m_nRecvTimeout;

  struct wreq__WriteRequest stReqMsg;
  struct wres__WriteResponse stResMsg;

  stReqMsg.return_.strCallingAETtile = strCallingAETitle;
  stReqMsg.return_.strCalledAETitle = strCalledAETitle;
  stReqMsg.return_.strPatientID = strPatientID;
  stReqMsg.return_.strPatientName = strPatientName;
  stReqMsg.return_.strProtocol = strProtocol;
  stReqMsg.return_.strSOPClassName = strSOPClassName;
  stReqMsg.return_.nNumOfInstance = nNumOfInstance;
  stReqMsg.return_.eStatus = Processing::hangpacs__Processing;

  nRet = p.WriteRequest(stReqMsg, &stResMsg);

  return nRet;
}

int CStatusLog::SendLog(const bool bIsAsync, LogLevel logLevelArg, LPCTSTR pszFormat, ...)
{
  if (false == m_bEnableStatus)
    return 0;

  va_list   ap;
  va_start(ap, pszFormat);

  //  set log level
  CString strLogLevelName;
  strLogLevelName = GetLogLevelToString(logLevelArg);

  //  set log message
  CString strLogMsg;
  strLogMsg.Format(_T("%s [%s] [P=%d,T=%d] %s\n"),
      CTime::GetCurrentTime().Format(_T("%Y/%m/%d %H:%M:%S")),
      strLogLevelName,
      GetCurrentProcessId(),
      GetCurrentThreadId(),
      pszFormat);

  _vtprintf(strLogMsg, ap);

  CString strFullLog;
  strFullLog.FormatV(strLogMsg, ap);
  OutputDebugString(strFullLog);

  va_end(ap);

  int nRet = SOAP_ERR;
  Proxy p(SOAP_IO_KEEPALIVE, SOAP_IO_KEEPALIVE);
  CStringA strSoapAddress = CStringA(m_strSoapAddress);
  p.soap_endpoint = strSoapAddress;
  p.connect_timeout = m_nConnectTimeout;
  p.accept_timeout = m_nAcceptTimeout;
  p.send_timeout = m_nSendTimeout;
  p.recv_timeout = m_nRecvTimeout;

  struct wlreq__WriteLogRequest stReqMsg;
  struct wlres__WriteLogResponse stResMsg;

  stReqMsg.return_.strLog = strFullLog.operator LPCWSTR();
  stReqMsg.return_.strAETitle = m_strAETitle.operator LPCWSTR();

  if (false == bIsAsync)
    nRet = p.WriteLog(stReqMsg, &stResMsg);
  else
    nRet = p.WriteLogAsync(stReqMsg);

  return nRet;
}

CString CStatusLog::GetLogLevelToString(LogLevel logLevelArg)
{
  CString strLogLevelName;

  switch (logLevelArg)
  {
  case LogLevel::NoLogging:
    strLogLevelName = _T("");
    break;
  case LogLevel::ErrorOnly:
    strLogLevelName = _T("E");
    break;
  case LogLevel::Simple:
    strLogLevelName = _T("S");
    break;
  case LogLevel::Detail:
    strLogLevelName = _T("D");
    break;
  case LogLevel::Developer:
    strLogLevelName = _T("Dev");
    break;
  }

  return strLogLevelName;
}
