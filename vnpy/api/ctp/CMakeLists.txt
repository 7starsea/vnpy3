cmake_minimum_required(VERSION 3.0)
project(vn_ctp_api)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR})

set(CTPAPI_PATH ${CMAKE_CURRENT_SOURCE_DIR}/ctpapi)

if(WIN32)
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		message(FATAL_ERROR "CTP API Currently does not support Win64")
	else()
		set(CTPAPI_PATH_LIB ${CTPAPI_PATH}/dll_win32)
	endif()

	file(GLOB CTPAPI_LIB_DLL ${CTPAPI_PATH_LIB}/*.dll)
	
else()
	set(CTPAPI_PATH_LIB ${CTPAPI_PATH}/x64_linux)
	file(GLOB CTPAPI_LIB_DLL ${CTPAPI_PATH_LIB}/*.so)
endif()

include_directories(${CTPAPI_PATH_LIB})	
unset(CTPAPI_MD_LIBRARY CACHE)
unset(CTPAPI_TD_LIBRARY CACHE)
find_library(CTPAPI_MD_LIBRARY NAMES thostmduserapi PATHS ${CTPAPI_PATH_LIB})
find_library(CTPAPI_TD_LIBRARY NAMES thosttraderapi PATHS ${CTPAPI_PATH_LIB})
	

message(STATUS "CTPAPI_LIB_DLL: " ${CTPAPI_LIB_DLL})
message(STATUS "CTPAPI_MD_LIBRARY: " ${CTPAPI_MD_LIBRARY})
message(STATUS "CTPAPI_TD_LIBRARY: " ${CTPAPI_TD_LIBRARY})

add_subdirectory(vnctpmd)
add_subdirectory(vnctptd)

