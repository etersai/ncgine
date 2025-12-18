:: ==============================
:: Build script for win32 NCgine
:: ==============================
@echo off

set PROGRAM_NAME=NCgine
set CFLAGS=/std:c11 /W4 /Zi /Od /DDEBUG

mkdir bin\plugins
pushd "bin"

cl /Fe:%PROGRAM_NAME% %CFLAGS% ..\src\main.c ..\src\engine\ncgine.c ..\src\engine\platform\p_win32.c

popd
:: Thanks Casey!