#include "Logger.h"
#include <atltime.h>
//#include <windows.h>
#include <processthreadsapi.h>
#include <share.h>
#include <locale.h>

const CString strDecorator = _T("********************************************************************************\n");

BOOL      CLogger::m_bDestroyed = FALSE;  
CLogger*  CLogger::m_pInstance = NULL;

CLogger::CLogger(void)
  : m_nCurLogLevel(LogLevel::Developer)
  , m_nCurLogPeriod(LogPeriod::OneFilePerOneHour)
  , m_strLogDir(_T(""))
  , m_strLogPrefix(_T(""))
  , m_strLogSuffix(_T(""))
  , m_strApplicationName(_T(""))
  , m_strApplicationVersion(_T(""))
  , m_strApplicationReleaseDate(_T(""))
{
}


CLogger::~CLogger(void)
{
  m_bDestroyed = TRUE;
}

CLogger* CLogger::GetInstance(void)
{
  if (m_bDestroyed)
  {
    m_pInstance = new CLogger();
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

VOID CLogger::SetLogLevel(LogLevel logLevelArg)
{
  m_nCurLogLevel = logLevelArg;
}

LogLevel CLogger::GetLogLevel()
{
  return m_nCurLogLevel;
}

VOID CLogger::SetLogPeriod(LogPeriod logPeriodArg)
{
  m_nCurLogPeriod = logPeriodArg;
}

LogPeriod CLogger::GetLogPeriod()
{
  return  m_nCurLogPeriod;
}

void CLogger::SetLogDir(LPCTSTR pszLogDirArg)
{
  m_strLogDir = pszLogDirArg;
}

LPCTSTR CLogger::GetLogDir()
{
  return m_strLogDir;
}

void CLogger::SetLogFilePrefix(LPCTSTR pszLogFilePrefixArg)
{
  m_strLogPrefix = pszLogFilePrefixArg;
}

LPCTSTR CLogger::GetLogFilePrefix()
{
  return m_strLogPrefix;
}

void CLogger::SetLogFileSuffix(LPCTSTR pszLogFileSuffixArg)
{
  m_strLogSuffix = pszLogFileSuffixArg;
}

LPCTSTR CLogger::GetLogFileSuffix()
{
  return m_strLogSuffix;
}

void CLogger::SetApplicationName(LPCTSTR pszAppNameArg)
{
  m_strApplicationName = pszAppNameArg;
}

LPCTSTR CLogger::GetApplicationName()
{
  return m_strApplicationName;
}

void CLogger::SetApplicationVersion(LPCTSTR pszAppVersionArg)
{
  m_strApplicationVersion = pszAppVersionArg;
}

LPCTSTR CLogger::GetApplicationVersion()
{
  return m_strApplicationVersion;
}

void CLogger::SetApplicationReleaseDate(LPCTSTR pszAppReleaseDateArg)
{
  m_strApplicationReleaseDate = pszAppReleaseDateArg;
}

LPCTSTR CLogger::GetApplicationReleaseDate()
{
  return m_strApplicationReleaseDate;
}

CString CLogger::GetApplicationInfo()
{
  CString strApplicaionInfo;

  strApplicaionInfo.Format(_T("ApplicationName:%s\tVersion:%s\t ReleaseDate:%s\n"),
    GetApplicationName(),
    GetApplicationVersion(),
    GetApplicationReleaseDate());

  strApplicaionInfo = strDecorator + strApplicaionInfo + strDecorator;

  return strApplicaionInfo;
}

CString CLogger::GetLogLevelToString(LogLevel logLevelArg)
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

BOOL CLogger::LogMessage(LogLevel logLevelArg, LPCTSTR pszFormat, ...)
{
  bool      bRet = FALSE;

  //  �α��� ������ ������ log �������� ���� ��쿡�� Trace�� �����ְ� 
  //  �ƹ��� �۾��� ���� ����
  if (m_nCurLogLevel < logLevelArg)
  {
#ifdef _DEBUG
    va_list   ap;
    va_start(ap, pszFormat);

    //  set log level
    CString strLogLevelName;
    strLogLevelName = GetLogLevelToString(logLevelArg);

    //  get current time
    CString strTime;
    if (LogPeriod::OneFilePerOneDay == GetLogPeriod())
      strTime = CTime::GetCurrentTime().Format("%Y%m%d");
    else
      strTime = CTime::GetCurrentTime().Format("%Y%m%d%H");

    //  set log message
    CString strLogMsg;
    strLogMsg.Format(_T("%s [%s] [P=%d,T=%d] %s\n"),
                     CTime::GetCurrentTime().Format(_T("%Y/%m/%d %H:%M:%S")),
                     strLogLevelName,
                     GetCurrentProcessId(),
                     GetCurrentThreadId(),
                     pszFormat);

    CStringA pszLogMsg(strLogMsg);
    pszLogMsg.FormatV((CStringA)strLogMsg, ap);

    bRet = true;

    va_end(ap);

    OutputDebugString((CString)pszLogMsg);
#endif // _DEBUG

    return bRet;
  }

  va_list   ap;
  va_start(ap, pszFormat);

  //  set log level
  CString strLogLevelName;
  strLogLevelName = GetLogLevelToString(logLevelArg);

  //  get current time
  CString strTime;
  if (LogPeriod::OneFilePerOneDay == GetLogPeriod())
  {
    strTime = CTime::GetCurrentTime().Format("%Y%m%d");
  }
  else
  {
    strTime = CTime::GetCurrentTime().Format("%Y%m%d%H");
  }
  

  //  set log file name
  CString strLogFilePath;
  if (0 < m_strLogSuffix.GetLength())
  {
    strLogFilePath.Format(_T("%s\\%s-%s-%s.log"),
      m_strLogDir,
      m_strLogPrefix,
      strTime,
      m_strLogSuffix);
  }
  else
  {
    strLogFilePath.Format(_T("%s\\%s-%s.log"),
      m_strLogDir,
      m_strLogPrefix,
      strTime);
  }
  
  //  thread-safe �ϵ��� mutex�� �ɾ��ش�
  CSingleLock SingleLock(&m_mtxLogger, TRUE);
  //SingleLock.Lock();

  //  open file
  //  ������ ù �κп� log�� ����� application�� ������ ����� ���ؼ� �Ʒ��� ���� ó���� ��
  //  ������ ó�� ������ ��쿡�� application ������ �����,
  //  �����ϴ� ������ �о���̴� ��쿡�� ������ ������ �α׸� ��� �Ѵ�.
  errno_t fileError;
  FILE  *pLogFile;
  fileError = _tfopen_s(&pLogFile, strLogFilePath, _T("r"));
  if (ERROR_SUCCESS != fileError)
  {
    fileError = _tfopen_s(&pLogFile, strLogFilePath, _T("wt+, ccs=UTF-8"));
    if (ERROR_SUCCESS != fileError)
    {
      bRet = FALSE;
      return bRet;
    }

    _ftprintf_p(pLogFile, GetApplicationInfo());
  }
  else
  {
    fclose(pLogFile);
    pLogFile = _tfsopen(strLogFilePath, _T("at+, ccs=UTF-8"), _SH_DENYNO);
    if (nullptr == pLogFile)
    {
      bRet = FALSE;
      return bRet;
    }
  }

  //  set log message
  CString strLogMsg;
  strLogMsg.Format(_T("%s [%s] [P=%d,T=%d] %s\n"),
    CTime::GetCurrentTime().Format(_T("%Y/%m/%d %H:%M:%S")),
    strLogLevelName,
    GetCurrentProcessId(),
    GetCurrentThreadId(),
    pszFormat);

  //  file�� ���
  //  locale ������ default�� �ٲٰ�, ���� ��� �� ������� ����
  TCHAR* pszOldLocaleTmp = _tsetlocale(LC_ALL, _T(""));
  TCHAR* pPreLocale = _tcsdup(pszOldLocaleTmp);
  _tsetlocale(LC_ALL, _T(""));
  _vftprintf_p(pLogFile, strLogMsg, ap);
  _tsetlocale(LC_ALL, pPreLocale);
  free(pPreLocale);

  //  debug�� ���
  CString strFullLog;
  strFullLog.FormatV(strLogMsg, ap);
  OutputDebugString(strFullLog);

  va_end(ap);
  fclose(pLogFile);

  bRet = true;

  //SingleLock.Unlock();

  return bRet;
}
