/**
@author Hang Seok, Lee 
@date   03/07/2019
@brief  
 
copyright(c) Tae Young Soft. All right reserved. 2019
*/

#pragma once

// #include <afx.h>
#include <afxmt.h>
#include <vector>

#ifdef	LOGGER_EXPORTS
#define	LOGGER_CLASS				__declspec(dllexport)
#else
#define	LOGGER_CLASS				__declspec(dllimport)
#endif

#define PIPE_NOLOG(...) \
  CPipeLogServer::GetInstance()->TransmitMessage(__VA_ARGS__);

#define PIPE_ERRONLY(...) \
  CPipeLogServer::GetInstance()->TransmitMessage(__VA_ARGS__);

#define PIPE_SIMPLE(...) \
  CPipeLogServer::GetInstance()->TransmitMessage(__VA_ARGS__);

#define PIPE_DETAIL(...) \
  CPipeLogServer::GetInstance()->TransmitMessage(__VA_ARGS__);

#define PIPE_DEV(...) \
  CPipeLogServer::GetInstance()->TransmitMessage(__VA_ARGS__);


/**
@brief  
*/
class LOGGER_CLASS CPipeLogServer
{
public:
  /**
  @brief		singleton pattern���� �����Ǿ� �ִ� �� Ŭ������ instance�� ��� ��
  @param		VOID
  @return		CPipeLogServer*
  */
  static  CPipeLogServer* GetInstance(void);

  /**
  @brief  
  @param  const CString & strName   '[AE title]_[port]' �������� �Է�
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
  CPipeLogServer(void);
  virtual ~CPipeLogServer(void);

  static void Create(void)
  {
    static CPipeLogServer m_Instance;
    m_pInstance = &m_Instance;
  }
  static void Kill()
  {
    m_pInstance->~CPipeLogServer();
  }

  static  CPipeLogServer* m_pInstance;
  static  bool            m_bDestroyed;

private:
  CString   m_strName;
  HANDLE    m_hThread;
  std::vector<void *> m_vecPipeInfo;
};
