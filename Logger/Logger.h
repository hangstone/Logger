#pragma once
/**
 @file 		Logger.h
 @version	v1.0
 @date		10/21/2013
 @author	Hang Seok, Lee
 @breif		
 @warning
 
 copyright(c) Tae Young Soft. All right reserved. 2013
*/

#pragma once

#include <afx.h>
#include <afxmt.h>

#ifdef	LOGGER_EXPORTS
#define	LOGGER_CLASS				__declspec(dllexport)
#else
#define	LOGGER_CLASS				__declspec(dllimport)
#endif

typedef enum _LogLevel
{
  NoLogging = 0,
  ErrorOnly,
  Simple,
  Detail,
  Developer
} LogLevel;

typedef enum _LogPeriod
{
  OneFilePerOneDay = 0,
  OneFilePerOneHour
} LogPeriod;

#define LOG_NOLOG(...) \
  CLogger::GetInstance()->LogMessage(LogLevel::NoLogging, __VA_ARGS__);

#define LOG_ERRONLY(...) \
  CLogger::GetInstance()->LogMessage(LogLevel::ErrorOnly, __VA_ARGS__);

#define LOG_SIMPLE(...) \
  CLogger::GetInstance()->LogMessage(LogLevel::Simple, __VA_ARGS__);

#define LOG_DETAIL(...) \
  CLogger::GetInstance()->LogMessage(LogLevel::Detail, __VA_ARGS__);

#define LOG_DEV(...) \
  CLogger::GetInstance()->LogMessage(LogLevel::Developer, __VA_ARGS__);


/**
@brief  logger class
*/
class LOGGER_CLASS CLogger
{
public:
  /**
  @brief  singleton pattern으로 구현되어 있는 본 클래스의 instance를 얻어 옴
  @param  void
  @return CLogger*
  */
  static  CLogger* GetInstance(void);

  void        SetLogLevel(LogLevel logLevelArg);
  LogLevel    GetLogLevel();

  void        SetLogPeriod(LogPeriod logPeriodArg);
  LogPeriod   GetLogPeriod();

  void        SetLogDir(LPCTSTR pszLogDirArg);
  LPCTSTR     GetLogDir();

  void        SetLogFilePrefix(LPCTSTR pszLogFilePrefixArg);
  LPCTSTR     GetLogFilePrefix();

  void        SetLogFileSuffix(LPCTSTR pszLogFileSuffixArg);
  LPCTSTR     GetLogFileSuffix();

  void        SetApplicationName(LPCTSTR pszAppNameArg);
  LPCTSTR     GetApplicationName();

  void        SetApplicationVersion(LPCTSTR pszAppVersionArg);
  LPCTSTR     GetApplicationVersion();

  void        SetApplicationReleaseDate(LPCTSTR pszAppReleaseDateArg);
  LPCTSTR     GetApplicationReleaseDate();

  /**
  @brief		CLogger::LogMessage
  					
  @warning
  @todo     log 메시지를 파일에 기록
  @param		LogLevel logLevel
  @param		LPCTSTR pszFormat
  @param		...
  @return		BOOL
  @auther		hangseok
  */
  virtual BOOL  LogMessage(LogLevel logLevel, LPCTSTR pszFormat, ...);

protected:
  /**
  @brief		CLogger::GetApplicationInfo
  					
  @warning
  @todo     log 파일의 최상단에 기록할 application 정보를 얻어 옴
  @return		CString
  @auther		hangseok
  */
  CString     GetApplicationInfo();
  
  /**
  @brief		CLogger::GetLogLevelToString
  					
  @warning
  @todo     log level 정보를 string 형태로 반환
  @param		LogLevel logLevel
  @return		CString
  @auther		hangseok
  */
  CString     GetLogLevelToString(LogLevel logLevel);

private:
  CLogger(void);
  virtual ~CLogger(void);

  static  VOID  Create()
  {
    static CLogger m_Instance;
    m_pInstance = &m_Instance;
  }
  static  VOID  KillLogger()
  {
    m_pInstance->~CLogger();
  }
  
  static  CLogger*  m_pInstance;
  static  BOOL      m_bDestroyed;
  CMutex        m_mtxLogger;

  LogLevel      m_nCurLogLevel;
  LogPeriod     m_nCurLogPeriod;
  
  //  
  CString       m_strLogDir;
  CString       m_strLogPrefix;
  CString       m_strLogSuffix;
  CString       m_strApplicationName;
  CString       m_strApplicationVersion;
  CString       m_strApplicationReleaseDate;
};

