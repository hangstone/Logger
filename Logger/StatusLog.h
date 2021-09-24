/**
@author Hang Seok, Lee 
@date   09/16/2021
@brief  

copyright(c) Tae Young Soft. All right reserved. 2021
*/

#pragma once

#include <afx.h>
#include <afxmt.h>
#include <string>

#include "Logger.h"

#ifdef	LOGGER_EXPORTS
#define	STATUS_CLASS				__declspec(dllexport)
#else
#define	STATUS_CLASS				__declspec(dllimport)
#endif

#define STATUS_NOLOG_SYNC(...) \
  { \
  CString str(__FUNCTION__); \
  str += _T(": "); \
  CStatusLog::GetInstance()->SendLog(false, LogLevel::NoLogging, str + __VA_ARGS__); \
  }

#define STATUS_ERRONLY_SYNC(...) \
  { \
  CString str(__FUNCTION__); \
  str += _T(": "); \
  CStatusLog::GetInstance()->SendLog(false, LogLevel::ErrorOnly, str + __VA_ARGS__); \
  }

#define STATUS_SIMPLE_SYNC(...) \
  { \
  CString str(__FUNCTION__); \
  str += _T(": "); \
  CStatusLog::GetInstance()->SendLog(false, LogLevel::Simple, str + __VA_ARGS__); \
  }

#define STATUS_DETAIL_SYNC(...) \
  { \
  CString str(__FUNCTION__); \
  str += _T(": "); \
  CStatusLog::GetInstance()->SendLog(false, LogLevel::Detail, str + __VA_ARGS__); \
  }

#define STATUS_DEV_SYNC(...) \
  { \
  CString str(__FUNCTION__); \
  str += _T(": "); \
  CStatusLog::GetInstance()->SendLog(false, LogLevel::Developer, str + __VA_ARGS__); \
  }

#define STATUS_NOLOG_ASYNC(...) \
  { \
  CString str(__FUNCTION__); \
  str += _T(": "); \
  CStatusLog::GetInstance()->SendLog(true, LogLevel::NoLogging, str + __VA_ARGS__); \
  }

#define STATUS_ERRONLY_ASYNC(...) \
  { \
  CString str(__FUNCTION__); \
  str += _T(": "); \
  CStatusLog::GetInstance()->SendLog(true, LogLevel::ErrorOnly, str + __VA_ARGS__); \
  }

#define STATUS_SIMPLE_ASYNC(...) \
  { \
  CString str(__FUNCTION__); \
  str += _T(": "); \
  CStatusLog::GetInstance()->SendLog(true, LogLevel::Simple, str + __VA_ARGS__); \
  }

#define STATUS_DETAIL_ASYNC(...) \
  { \
  CString str(__FUNCTION__); \
  str += _T(": "); \
  CStatusLog::GetInstance()->SendLog(true, LogLevel::Detail, str + __VA_ARGS__); \
  }

#define STATUS_DEV_ASYNC(...) \
  { \
  CString str(__FUNCTION__); \
  str += _T(": "); \
  CStatusLog::GetInstance()->SendLog(true, LogLevel::Developer, str + __VA_ARGS__); \
  }

/**
@brief  soap 통신을 통해 status log를 전송하는 class
*/
class STATUS_CLASS CStatusLog
{
public:
  /**
  @brief  singleton pattern으로 구현되어 있는 본 클래스의 instance를 얻어 옴
  @param  void
  @return CLogger*
  */
  static  CStatusLog* GetInstance(void);

  /**
  @brief  
  @param  void
  @return void
  */
  void MakeSoapAddress(void);

  /**
  @brief  
  @param  const std::wstring & strCallingAETitle
  @param  const std::wstring & strCalledAETitle
  @param  const int & nProcessing
          0 : begin
          1 : processing
          2 : end
  @return int
  */
  virtual int SendRecvStatus(const std::wstring& strCallingAETitle,
                             const std::wstring& strCalledAETitle, 
                             const int& nProcessing);

  /**
  @brief  
  @param  const std::wstring & strCallingAETitle
  @param  const std::wstring & strCalledAETitle
  @param  const std::wstring & strPatientID
  @param  const std::wstring & strPatientName
  @param  const std::wstring & strProtocol
  @param  const std::wstring & strSOPClassName
  @param  const int & nNumOfInstance
  @return int
  */
  virtual int SendRecvStatus(const std::wstring& strCallingAETitle,
                             const std::wstring& strCalledAETitle,
                             const std::wstring& strPatientID,
                             const std::wstring& strPatientName,
                             const std::wstring& strProtocol,
                             const std::wstring& strSOPClassName,
                             const int& nNumOfInstance);
  /**
  @brief  
  @param  const bool bIsAsync
  @param  LogLevel logLevelArg
  @param  LPCTSTR pszFormat
  @param  ...
  @return int
  */
  virtual int SendLog(const bool bIsAsync, LogLevel logLevelArg, LPCTSTR pszFormat, ...);

protected:
  CString GetLogLevelToString(LogLevel logLevelArg);

public:
  const bool& GetEnableStatus() const { return m_bEnableStatus; }
  void SetEnableStatus(const bool& val) { m_bEnableStatus = val; }
  const CString& GetSoapIP() const { return m_strSoapIP; }
  void SetSoapIP(const CString& val) { m_strSoapIP = val; }
  const int& GetSoapPort() const { return m_nSoapPort; }
  void SetSoapPort(const int& val) { m_nSoapPort = val; }
  const int& GetConnectTimeout() const { return m_nConnectTimeout; }
  void SetConnectTimeout(const int& val) { m_nConnectTimeout = val; }
  const int& GetAcceptTimeout() const { return m_nAcceptTimeout; }
  void SetAcceptTimeout(const int& val) { m_nAcceptTimeout = val; }
  const int& GetSendTimeout() const { return m_nSendTimeout; }
  void SetSendTimeout(const int& val) { m_nSendTimeout = val; }
  const int& GetRecvTimeout() const { return m_nRecvTimeout; }
  void SetRecvTimeout(const int& val) { m_nRecvTimeout = val; }
  const CString& GetAETitle() const { return m_strAETitle; }
  void SetAETitle(const CString& val) { m_strAETitle = val; }

private:
  CStatusLog(void);
  virtual ~CStatusLog(void);

  static  void  Create()
  {
    static CStatusLog m_Instance;
    m_pInstance = &m_Instance;
  }
  static  void  KillLogger()
  {
    m_pInstance->~CStatusLog();
  }

  static  CStatusLog* m_pInstance;
  static  bool        m_bDestroyed;

private:
  //  status log 기능 사용여부를 결정
  bool      m_bEnableStatus;

  CString   m_strSoapAddress;

  CString   m_strSoapIP;

  int       m_nSoapPort;

  int       m_nConnectTimeout;

  int       m_nAcceptTimeout;

  int       m_nSendTimeout;

  int       m_nRecvTimeout;

  CString   m_strAETitle;
};

