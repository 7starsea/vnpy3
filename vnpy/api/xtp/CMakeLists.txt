cmake_minimum_required(VERSION 3.0)
project(vn_xtp_api)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR})

set(XTPAPI_PATH ${CMAKE_CURRENT_SOURCE_DIR}/xtpapi-1.1.16)
include_directories(${XTPAPI_PATH}/include)

if(WIN32)
	if( (VNPY_API_XTP_WIN EQUAL 64) AND (CMAKE_SIZEOF_VOID_P EQUAL 8))
		find_library(XTPAPI_MD_LIBRARY NAMES xtpquoteapi PATHS ${XTPAPI_PATH}/win64/dll)
		find_library(XTPAPI_TD_LIBRARY NAMES xtptraderapi PATHS ${XTPAPI_PATH}/win64/dll)
		
		file(GLOB XTPAPI_LIB_DLL ${XTPAPI_PATH}/win64/dll/*.dll)
	else()
		find_library(XTPAPI_MD_LIBRARY NAMES xtpquoteapi PATHS ${XTPAPI_PATH}/win32/dll) 
		find_library(XTPAPI_TD_LIBRARY NAMES xtptraderapi PATHS ${XTPAPI_PATH}/win32/dll)
		
		file(GLOB XTPAPI_LIB_DLL ${XTPAPI_PATH}/win32/dll/*.dll)
	endif()
else()
	find_library(XTPAPI_MD_LIBRARY NAMES xtpquoteapi PATHS ${XTPAPI_PATH}/linux) 
	find_library(XTPAPI_TD_LIBRARY NAMES xtptraderapi PATHS ${XTPAPI_PATH}/linux)
	
	file(GLOB XTPAPI_LIB_DLL ${XTPAPI_PATH}/linux/*.so)
endif()

message(STATUS "XTPAPI_LIB_DLL: " ${XTPAPI_LIB_DLL})
message(STATUS "XTPAPI_MD_LIBRARY: " ${XTPAPI_MD_LIBRARY})
message(STATUS "XTPAPI_TD_LIBRARY: " ${XTPAPI_TD_LIBRARY})

add_subdirectory(vnxtpquote)
add_subdirectory(vnxtptrader)

