// TestLogger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Logger.h"
#include "PipeServer.h"

#ifdef _DEBUG
  #ifndef _X64
    #pragma comment(lib, "/debug/loggerd.lib")
  #else
    #pragma comment(lib, "/x64/debug/loggerd_x64.lib")
#endif // !_64
#else
  #ifndef _X64
    #pragma comment(lib, "/release/logger.lib")
  #else
    #pragma comment(lib, "/x64/release/logger_x64.lib")
  #endif // !_x64
#endif // _DEBUG

#define LOG_PIPE_NOLOG(...) \
  LOG_NOLOG(__VA_ARGS__) \
  PIPE_NOLOG(__VA_ARGS__)

#define LOG_PIPE_ERRONLY(...) \
  LOG_ERRONLY(__VA_ARGS__) \
  PIPE_ERRONLY(__VA_ARGS__)

#define LOG_PIPE_SIMPLE(...) \
  LOG_SIMPLE(__VA_ARGS__) \
  PIPE_SIMPLE(__VA_ARGS__)

#define LOG_PIPE_DETAIL(...) \
  LOG_DETAIL(__VA_ARGS__) \
  PIPE_DETAIL(__VA_ARGS__)

#define LOG_PIPE_DEV(...) \
  LOG_DEV(__VA_ARGS__) \
  PIPE_DEV(__VA_ARGS__)


int _tmain(int argc, _TCHAR* argv[])
{
#ifdef _DEBUG
  //_CrtSetBreakAlloc(144);
#endif // _DEBUG

  BOOL bRet = FALSE;
  CLogger* pLogger = CLogger::GetInstance();

  pLogger->SetLogDir(_T("C:\\TYsoft\\log"));
  pLogger->SetLogFilePrefix(_T("testLog"));
  pLogger->SetLogLevel(LogLevel::Developer);
  pLogger->SetLogPeriod(LogPeriod::OneFilePerOneDay);
  CLogger::GetInstance()->LogMessage(LogLevel::ErrorOnly, _T("asd"));

  bRet = CPipeLogServer::GetInstance()->Initialize(_T("TY_RCV119_104"));
  bRet = CPipeLogServer::GetInstance()->IsConnected();
  CPipeLogServer::GetInstance()->TransmitMessage(_T("test"));

  for (int i=0; i<10; i++)
  {
    INT nDec = 10;
    CString strTest = _T("제타");
    CString strEng = _T("zxc");

    LOG_PIPE_NOLOG(_T("%d %s %s"), nDec, strTest, strEng);
    LOG_PIPE_ERRONLY(_T("%s"), static_cast<CString>("한글"));
    LOG_PIPE_SIMPLE(_T("%d %s %s"), nDec, strTest, strEng);
    LOG_PIPE_DETAIL(_T("%s"), static_cast<CString>("한글"));
    LOG_PIPE_DEV(_T("%d %s %s"), nDec, strTest, strEng);
  }

#ifdef _DEBUG
//  _CrtMemDumpAllObjectsSince(0);
#endif // _DEBUG

  return 0;
}

