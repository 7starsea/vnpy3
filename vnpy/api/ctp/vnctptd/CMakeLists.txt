
set(source_dir ${CMAKE_CURRENT_SOURCE_DIR})

set(headers
	${source_dir}/vnctptd.h
	)
set(sources 					
	${source_dir}/vnctptd.cpp
	)

PYTHON_ADD_MODULE(vnctptd  ${headers} ${sources})
TARGET_include_directories(vnctptd PUBLIC ${PYTHON_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(vnctptd ${Boost_LIBRARIES} ${Boost_PY_LIBRARIES} ${PYTHON_LIBRARIES} ${CTPAPI_TD_LIBRARY}) 


add_custom_command(TARGET vnctptd POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CTPAPI_LIB_DLL}  ${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE})
