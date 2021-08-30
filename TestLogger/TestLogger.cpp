// TestLogger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Logger.h"
#include "PipeServer.h"
#include "PipeStatusServer.h"

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

  CPipeLogServer* pLogServer = CPipeLogServer::GetInstance();
  bRet = pLogServer->Initialize(_T("TY_RCV119_104"));
  Sleep(1000);
  //bRet = CPipeLogServer::GetInstance()->IsConnected();
  pLogServer->TransmitMessage(_T("test"));

  CPipeStatusServer* pStatServer = CPipeStatusServer::GetInstance();
  bRet = pStatServer->Initialize(_T("TY_RCV119_1044"));
  pStatServer->TransmitMessage(_T("123|456|789|234|567"));
  

  for (int i=0; i<10; i++)
  {
    INT nDec = 10;
    std::wstring strTest = _T("제타");
    CString strEng = _T("zxc");

    LOG_PIPE_NOLOG(_T("%d %s %s"), nDec, strTest.c_str(), strEng);
    LOG_PIPE_ERRONLY(_T("%s"), static_cast<CString>("한글"));
    LOG_PIPE_SIMPLE(_T("%d %s %s"), nDec, strTest.c_str(), strEng);
    LOG_PIPE_DETAIL(_T("%s"), static_cast<CString>("한글"));
    LOG_PIPE_DEV(_T("%d %s %s"), nDec, strTest.c_str(), strEng);
    
    LERR(_T("%s"), static_cast<CString>("한글"));
    LERR(_T("%d %s %s"), nDec, strTest.c_str(), strEng);

    CString strMsg00 = _T("항항항|456|789|234|567|");
    CString strMsg01 = _T("000|999|000|999|000|");
    PIPE_STATUS(strMsg00 + _T("0"));
    PIPE_STATUS(strMsg00 + _T("1"));
    PIPE_STATUS(strMsg01 + _T("0"));
    PIPE_STATUS(strMsg01 + _T("1"));
    PIPE_STATUS(strMsg00 + _T("2"));
    PIPE_STATUS(strMsg01 + _T("2"));
  }

#ifdef _DEBUG
//  _CrtMemDumpAllObjectsSince(0);
#endif // _DEBUG

  return 0;
}

