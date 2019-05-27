/**
@author Hang Seok, Lee 
@date   04/08/2019
@brief  
 
copyright(c) Tae Young Soft. All right reserved. 2019
*/

#pragma once

#include <afxmt.h>
#include <vector>

#ifdef	LOGGER_EXPORTS
#define	LOGGER_CLASS				__declspec(dllexport)
#else
#define	LOGGER_CLASS				__declspec(dllimport)
#endif

#define PIPE_STATUS(...) \
  CPipeStatusServer::GetInstance()->TransmitMessage(__VA_ARGS__);

/**
@brief  
*/
class LOGGER_CLASS CPipeStatusServer
{
public:
  /**
  @brief		singleton pattern으로 구현되어 있는 본 클래스의 instance를 얻어 옴
  @param		VOID
  @return		CPipeLogServer*
  */
  static  CPipeStatusServer* GetInstance(void);

  /**
  @brief  
  @param  const CString & strName   '[AE title]_[port]' 형식으로 입력
  @return bool
  */
  BOOL Initialize(const CString& strName);

  /**
  @brief  
  @return void
  */
  void Finalize();

  /**
  @brief  
  @param  const CString & strLog
  @return void
  */
  void TransmitMessage(const CString& strLog);

  /**
  @brief  
  @param  LPCTSTR pszFormat
  @param  ...
  @return void
  */
  void TransmitMessage(LPCTSTR pszFormat, ...);

  /**
  @brief  
  @param  void
  @return BOOL
  */
  BOOL IsConnected(void);

private:
  CPipeStatusServer(void);
  virtual ~CPipeStatusServer(void);

  static void Create(void)
  {
    static CPipeStatusServer m_Instance;
    m_pInstance = &m_Instance;
  }
  static void Kill()
  {
    m_pInstance->~CPipeStatusServer();
  }

  static  CPipeStatusServer* m_pInstance;
  static  bool            m_bDestroyed;

private:
  CString   m_strName;
  HANDLE    m_hThread;
  std::vector<void *> m_vecPipeInfo;
};

