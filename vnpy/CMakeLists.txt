cmake_minimum_required(VERSION 3.0)
project(vn_xtp_api)


set(BUILD_SHARED_LIBS OFF)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# # load configuration
include(configuration)

if(NOT (BOOST_ROOT AND IS_DIRECTORY ${BOOST_ROOT}))
	message(FATAL_ERROR "BOOST_ROOT:" ${BOOST_ROOT} " DOES NOT EXIST! Please edit file cmake/configuration.cmake")
endif()
if(NOT (PYTHON_INCLUDE_DIR AND IS_DIRECTORY ${PYTHON_INCLUDE_DIR}))
	message(FATAL_ERROR "PYTHON_INCLUDE_DIR:" ${PYTHON_INCLUDE_DIR} " DOES NOT EXIST! Please edit file cmake/configuration.cmake")
endif()

include(vnpy3common)
init_compiler_system()


FIND_PACKAGE(PythonInterp)
FIND_PACKAGE(PythonLibs)
message(STATUS "PYTHON_INCLUDE_DIRS: " ${PYTHON_INCLUDE_DIRS})
message(STATUS "PYTHON_LIBRARIES: " ${PYTHON_LIBRARIES})
message(STATUS "PYTHON_LIB_VERSION: " ${PYTHONLIBS_VERSION_STRING})

# # build python extension dynamically
set(Boost_USE_STATIC_LIBS        OFF)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)

find_package(Boost 1.57 COMPONENTS python)
if(NOT Boost_FOUND)
	find_package(Boost 1.57 COMPONENTS python3 REQUIRED)
endif()
set(Boost_PY_LIBRARIES ${Boost_LIBRARIES})
message(status "** Boost_PY_Libraries: ${Boost_PY_LIBRARIES}")

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
find_package(Boost 1.57 COMPONENTS thread system atomic date_time chrono REQUIRED)

message(status "**Boost_LIBRARIES: ${Boost_LIBRARIES}")
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
 
add_subdirectory(api/xtp)


