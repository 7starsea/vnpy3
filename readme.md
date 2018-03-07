### Introduction:
vnpy3 is a simplified vn.py running in python3.
The core code is borrowed from vnpy: https://github.com/vnpy/vnpy
We are still in development.
Currently, this project targets experienced users.

### Contribution:
- simplified the building process with cmake
- supporting python3

### Supporting Interface:
- xtp

### Dependency:
1. boost (1.57 or later) [tested: 1.65]
2. cmake (3.0 or later)	 [tested: 3.9]
3. visual studio (2011 or later) [tested: 2013]

Please let me know if you have any question and if you want to add more tested enviroments.

### Compiling:
1. edit configuration file: vnpy/cmake/configuration.cmake to set proper path for boost and python
2. On windows: edit compile.bat by setting proper location for MSBuild.exe and cmake.exe
3. run compile.bat or compile.sh depending on your system

---
### License
MIT 