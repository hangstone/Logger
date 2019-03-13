#include "PipeMessage.h"

#define MAX_BUFFER_SIZE       (4096)
#define SIZE_IDENTIFIER       (5)
#define SIZE_MESSAGE_TYPE     (1)
#define SIZE_MESSAGE_LENGTH   (4)
#define NAME_IDENTIFIER       ("ZeTTA")


CPipeMessage::CPipeMessage(void)
{
  m_pMessage = nullptr;
  Clear();
}


CPipeMessage::~CPipeMessage(void)
{
  Clear();
}

void CPipeMessage::Clear(void)
{
  ZeroMemory(m_szIdentifier, sizeof(m_szIdentifier));
  m_chMessageType = 0;
  m_uSizeOfMessage = 0;
  
  if (nullptr != m_pMessage)
  {
    delete [] m_pMessage;
    m_pMessage = nullptr;
  }
}

void CPipeMessage::EmptyPipe(HANDLE hNamedPipe)
{
  BOOL bRet = FALSE;
  DWORD dwRead = 0;
  unsigned char buf[4096];

  do 
  {
    bRet = ReadFile(hNamedPipe, buf, MAX_BUFFER_SIZE, &dwRead, nullptr);
    if (FALSE == bRet && ERROR_SUCCESS != GetLastError())
      break;
  } while (0 == dwRead);
}

BOOL CPipeMessage::Read(HANDLE hNamedPipe)
{
  BOOL bRet = FALSE;
  DWORD dwRead = 0;
  DWORD dwTotalRead = 0;

  bRet = ReadFile(hNamedPipe, m_szIdentifier, SIZE_IDENTIFIER, &dwRead, nullptr);
  if (FALSE == bRet || SIZE_IDENTIFIER != dwRead)
    return FALSE;

  //  check identifier
  if (0 != strcmp(m_szIdentifier, NAME_IDENTIFIER))
    goto on_Failed;

  //  check type of message
  bRet = ReadFile(hNamedPipe, &m_chMessageType, SIZE_MESSAGE_TYPE, &dwRead, nullptr);
  if (FALSE == bRet || SIZE_MESSAGE_TYPE != dwRead)
    goto on_Failed;

  bRet = ReadFile(hNamedPipe, &m_uSizeOfMessage, SIZE_MESSAGE_LENGTH, &dwRead, nullptr);
  if (FALSE == bRet || SIZE_MESSAGE_LENGTH != dwRead)
    goto on_Failed;

  m_pMessage = new unsigned char[m_uSizeOfMessage];

  do 
  {
    bRet = ReadFile(hNamedPipe, 
                    m_pMessage + dwTotalRead, 
                    m_uSizeOfMessage, 
                    &dwRead, 
                    nullptr);
    if (FALSE == bRet && ERROR_SUCCESS != GetLastError())
      break;
    
    dwTotalRead += dwRead;
  } while (dwTotalRead < m_uSizeOfMessage);

  return bRet;

on_Failed:
  EmptyPipe(hNamedPipe);
  return FALSE;
}

BOOL CPipeMessage::Write(HANDLE hNamedPipe)
{
  BOOL bRet = FALSE;
  DWORD dwWritten = 0;

  memcpy(m_szIdentifier, NAME_IDENTIFIER, SIZE_IDENTIFIER);

  bRet = WriteFile(hNamedPipe, m_szIdentifier, SIZE_IDENTIFIER, &dwWritten, nullptr);
  if (FALSE == bRet || SIZE_IDENTIFIER != dwWritten)
    return FALSE;
  
  bRet = WriteFile(hNamedPipe, &m_chMessageType, SIZE_MESSAGE_TYPE, &dwWritten, nullptr);
  if (FALSE == bRet || SIZE_MESSAGE_TYPE != dwWritten)
    return FALSE;

  bRet = WriteFile(hNamedPipe, &m_uSizeOfMessage, SIZE_MESSAGE_LENGTH, &dwWritten, nullptr);
  if (FALSE == bRet || SIZE_MESSAGE_LENGTH != dwWritten)
    return FALSE;

  bRet = WriteFile(hNamedPipe, m_pMessage, m_uSizeOfMessage, &dwWritten, nullptr);
  if (FALSE == bRet || m_uSizeOfMessage != dwWritten)
    return FALSE;

  return FlushFileBuffers(hNamedPipe);
}

void CPipeMessage::SetData(void* pData, unsigned int uSizeOfData)
{
  if (this->m_pMessage)
    delete [] this->m_pMessage;

  this->m_uSizeOfMessage = uSizeOfData;
  this->m_pMessage = new unsigned char[uSizeOfData];
  memcpy(this->m_pMessage, pData, uSizeOfData);
}
