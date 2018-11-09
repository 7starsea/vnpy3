@echo off
set cmake="F:\Program Files (x86)\CMake\bin\cmake.exe"

if not exist build mkdir build
cd build
%cmake% ..

REM %cmake%  --build . --target ALL_BUILD --config Debug
%cmake%  --build . --target ALL_BUILD --config Release

cd ..
::rmdir /S /Q build


pause