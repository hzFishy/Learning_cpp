@echo off
setlocal


set file=Main.cpp


echo Compiling %file%...
g++ %file% -o App

endlocal
