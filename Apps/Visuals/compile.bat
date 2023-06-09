@echo off
setlocal



echo Compiling %file%...
g++ -O2 main.cpp ../default_functions.cpp WallOfIllusions.cpp -o App -static -static-libgcc -static-libstdc++

pause
endlocal
