/**
@author Hang Seok, Lee 
@date   03/07/2019
@brief  named pipe를 위한 message를 관리하는 class
 
copyright(c) Tae Young Soft. All right reserved. 2019
*/

#pragma once

#include <concrt.h>
#include <wtypes.h>

#ifdef	LOGGER_EXPORTS
#define	LOGGER_CLASS				__declspec(dllexport)
#else
#define	LOGGER_CLASS				__declspec(dllimport)
#endif

/**
@brief  
*/
class LOGGER_CLASS CPipeMessage
{
public:
  CPipeMessage(void);
  virtual ~CPipeMessage(void);

  /**
  @brief  초기화 및 정리를 수행
  @param  void
  @return void
  */
  void Clear(void);

  /**
  @brief  주어진 named pipe를 비움
  @param  HANDLE hNamedPipe
  @return void
  */
  void EmptyPipe(HANDLE hNamedPipe);

  /**
  @brief  
  @param  HANDLE hNamedPipe
  @return BOOL
  */
  BOOL Read(HANDLE hNamedPipe);

  /**
  @brief  
  @param  HANDLE hNamedPipe
  @return BOOL
  */
  BOOL Write(HANDLE hNamedPipe);

  /**
  @brief  
  @param  void * pData
  @param  unsigned int uSizeOfData
  @return void
  */
  void SetData(void* pData, unsigned int uSizeOfData);

private:
  char            m_szIdentifier[5];
  unsigned char   m_chMessageType;
  unsigned int    m_uSizeOfMessage;
  unsigned char*  m_pMessage;
};

