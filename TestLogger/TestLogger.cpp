// TestLogger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Logger.h"

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


int _tmain(int argc, _TCHAR* argv[])
{
#ifdef _DEBUG
  //_CrtSetBreakAlloc(144);
#endif // _DEBUG

  CLogger* pLogger = CLogger::GetInstance(_T("testLog"));

  pLogger->SetLogDir(_T("C:\\TYsoft\\test"));
  pLogger->SetLogFilePrefix(_T("testLog"));
  pLogger->SetLogLevel(LogLevel::Developer);
  pLogger->SetLogPeriod(LogPeriod::OneFilePerOneDay);
  CLogger::GetInstance(_T("testLog"))->LogMessage(LogLevel::ErrorOnly, _T("asd"));

  for (int i=0; i<10 ; i++)
  {
    pLogger->LogMessage(LogLevel::ErrorOnly, 
        _T("%d %s %s"), 
        10, 
        _T("�׽�Ʈ"), 
        _T("zxc"));
  }

#ifdef _DEBUG
//  _CrtMemDumpAllObjectsSince(0);
#endif // _DEBUG

  return 0;
}

