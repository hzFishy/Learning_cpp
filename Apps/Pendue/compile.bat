@echo off
setlocal

echo Compiling ...
g++ -O2 main.cpp ../default_functions.cpp -o App -static -static-libgcc -static-libstdc++

pause
endlocal
