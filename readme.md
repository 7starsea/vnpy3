### Introduction:
vnpy3 is a simplified vn.py running in python3.
The core code is borrowed from vnpy: https://github.com/vnpy/vnpy
We are still in development.
Currently, this project targets experienced users.

### Contribution:
- simplified the building process with cmake
- supporting python3, theoretically, it also supports python2 (not tested)

### Supporting Interface:
- ctp
- xtp

### Dependency:
1. boost (1.57 or later) [tested: 1.65]
2. cmake (3.0 or later)	 [tested: 3.9]
3. visual studio (2011 or later) [tested: 2013]

Please let me know if you have any question and if you want to add more tested enviroments.

### Compiling:
1. edit configuration file: vnpy/cmake/configuration.cmake to set proper path for boost and python;

    1.1 We currently use shared-lib for python/boost.python and static-lib for other boost-libraries,
    
    1.2 you may want to do some changes (see Line 20-31, 40-42 in vnpy/CMakeLists.txt).
2. On windows: edit compile.bat by setting proper location for MSBuild.exe and cmake.exe;
3. run compile.bat or compile.sh depending on your system.

---
### Belief
Write once, use everywhere.

### License
MIT 