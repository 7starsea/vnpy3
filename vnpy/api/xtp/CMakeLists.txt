cmake_minimum_required(VERSION 3.0)
project(vn_xtp_api)


# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR})

set(XTPAPI_PATH xtpapi)
include_directories(${XTPAPI_PATH})

find_library(XTPAPI_MD_LIBRARY NAMES xtpquoteapi PATHS ${XTPAPI_PATH}) 
find_library(XTPAPI_TD_LIBRARY NAMES xtptraderapi PATHS ${XTPAPI_PATH})

message(STATUS "XTPAPI_MD_LIBRARY: " ${XTPAPI_MD_LIBRARY})
message(STATUS "XTPAPI_TD_LIBRARY: " ${XTPAPI_TD_LIBRARY})
 

add_subdirectory(vnxtpquote)
add_subdirectory(vnxtptrader)


