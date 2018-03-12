cmake_minimum_required(VERSION 3.0)
project(vn_xtp_api)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR})

set(XTPAPI_PATH ${CMAKE_CURRENT_SOURCE_DIR}/xtpapi-1.1.16)


if(WIN32)
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(XTPAPI_PATH_LIB ${XTPAPI_PATH}/win64/dll)
	else()
		set(XTPAPI_PATH_LIB ${XTPAPI_PATH}/win32/dll)
	endif()
	
	file(GLOB XTPAPI_LIB_DLL ${XTPAPI_PATH_LIB}/*.dll)
else()
	set(XTPAPI_PATH_LIB ${XTPAPI_PATH}/linux)
	
	file(GLOB XTPAPI_LIB_DLL ${XTPAPI_PATH_LIB}/*.so)
endif()

include_directories(${XTPAPI_PATH}/include)
find_library(XTPAPI_MD_LIBRARY NAMES xtpquoteapi PATHS ${XTPAPI_PATH_LIB})
find_library(XTPAPI_TD_LIBRARY NAMES xtptraderapi PATHS ${XTPAPI_PATH_LIB})

message(STATUS "XTPAPI_LIB_DLL: " ${XTPAPI_LIB_DLL})
message(STATUS "XTPAPI_MD_LIBRARY: " ${XTPAPI_MD_LIBRARY})
message(STATUS "XTPAPI_TD_LIBRARY: " ${XTPAPI_TD_LIBRARY})

add_subdirectory(vnxtpquote)
add_subdirectory(vnxtptrader)

