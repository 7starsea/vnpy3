@echo off
set "MSBuild=C:\Windows\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe"
set cmake="F:\Program Files (x86)\CMake\bin\cmake.exe"


if not exist build mkdir build
cd build
%cmake% ..

::%MSBuild% ALL_BUILD.vcxproj /nologo /t:build /p:Configuration=Debug
%MSBuild% ALL_BUILD.vcxproj /nologo /t:build /p:Configuration=Release

cd ..
::rmdir /S /Q build


::pause