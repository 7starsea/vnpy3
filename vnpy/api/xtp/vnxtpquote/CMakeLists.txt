
add_definitions(-DBUILD_XTP_MD)
set(source_dir ${CMAKE_CURRENT_SOURCE_DIR})

set(headers
	${source_dir}/vnxtpquote.h
	)
set(sources 					
	${source_dir}/vnxtpquote.cpp
	)

PYTHON_ADD_MODULE(vnxtpquote  ${headers} ${sources})
TARGET_include_directories(vnxtpquote PUBLIC ${PYTHON_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(vnxtpquote ${Boost_LIBRARIES} ${Boost_PY_LIBRARIES} ${PYTHON_LIBRARIES} ${XTPAPI_MD_LIBRARY}) 

add_custom_command(TARGET vnxtpquote POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different ${XTPAPI_LIB_DLL} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE})