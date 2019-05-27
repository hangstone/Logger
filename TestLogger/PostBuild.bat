@ECHO OFF

SET SRC_DBG_x86_DIR=..\Debug
SET SRC_DBG_x64_DIR=..\x64\Debug
SET SRC_REL_x86_DIR=..\Release
SET SRC_REL_x64_DIR=..\x64\Release

SET SRC_LOG_DIR=..\Logger

SET LIB_DIR=D:\common\TY_Lib\logger

SET	INCLUDEDIR=\inc
SET LIB_DBG_DIR=\lib\debug
SET LIB_REL_DIR=\lib\release
SET BIN_DBG_DIR=\bin\debug
SET BIN_REL_DIR=\bin\release

SET COPYOPT=/K /R /Y

XCOPY %SRC_LOG_DIR%\Logger.h					%SRC_DBG_x86_DIR%\*.* %COPYOPT%
XCOPY %SRC_LOG_DIR%\PipeMessage.h				%SRC_DBG_x86_DIR%\*.* %COPYOPT%
XCOPY %SRC_LOG_DIR%\PipeServer.h				%SRC_DBG_x86_DIR%\*.* %COPYOPT%
XCOPY %SRC_LOG_DIR%\PipeStatusServer.h			%SRC_DBG_x86_DIR%\*.* %COPYOPT%

REM -- COPY TY_Lib (header)
XCOPY %SRC_DBG_x86_DIR%\Logger.h				%LIB_DIR%%INCLUDEDIR%\*.* %COPYOPT%
XCOPY %SRC_DBG_x86_DIR%\PipeMessage.h			%LIB_DIR%%INCLUDEDIR%\*.* %COPYOPT%
XCOPY %SRC_DBG_x86_DIR%\PipeServer.h			%LIB_DIR%%INCLUDEDIR%\*.* %COPYOPT%
XCOPY %SRC_DBG_x86_DIR%\PipeStatusServer.h		%LIB_DIR%%INCLUDEDIR%\*.* %COPYOPT%

REM -- COPY TY_Lib (library)
XCOPY %SRC_DBG_x86_DIR%\LoggerD.lib				%LIB_DIR%%LIB_DBG_DIR%\*.* %COPYOPT%
XCOPY %SRC_DBG_x64_DIR%\LoggerD_x64.lib			%LIB_DIR%%LIB_DBG_DIR%\*.* %COPYOPT%
XCOPY %SRC_REL_x86_DIR%\Logger.lib				%LIB_DIR%%LIB_REL_DIR%\*.* %COPYOPT%
XCOPY %SRC_REL_x64_DIR%\Logger_x64.lib			%LIB_DIR%%LIB_REL_DIR%\*.* %COPYOPT%

XCOPY %SRC_DBG_x86_DIR%\LoggerD.dll				%LIB_DIR%%BIN_DBG_DIR%\*.* %COPYOPT%
XCOPY %SRC_DBG_x86_DIR%\LoggerD.pdb				%LIB_DIR%%BIN_DBG_DIR%\*.* %COPYOPT%
XCOPY %SRC_DBG_x64_DIR%\LoggerD_x64.dll			%LIB_DIR%%BIN_DBG_DIR%\*.* %COPYOPT%
XCOPY %SRC_DBG_x64_DIR%\LoggerD_x64.pdb			%LIB_DIR%%BIN_DBG_DIR%\*.* %COPYOPT%
XCOPY %SRC_REL_x86_DIR%\Logger.dll				%LIB_DIR%%BIN_REL_DIR%\*.* %COPYOPT%
XCOPY %SRC_REL_x86_DIR%\Logger.pdb				%LIB_DIR%%BIN_REL_DIR%\*.* %COPYOPT%
XCOPY %SRC_REL_x64_DIR%\Logger_x64.dll			%LIB_DIR%%BIN_REL_DIR%\*.* %COPYOPT%
XCOPY %SRC_REL_x64_DIR%\Logger_x64.pdb			%LIB_DIR%%BIN_REL_DIR%\*.* %COPYOPT%