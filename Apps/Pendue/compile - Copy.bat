@echo off
setlocal



echo Compiling %file%...
g++ main.cpp ../default_functions.cpp -o App
pause
endlocal
