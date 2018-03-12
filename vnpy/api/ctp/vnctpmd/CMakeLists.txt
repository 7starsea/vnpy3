
set(source_dir ${CMAKE_CURRENT_SOURCE_DIR})

set(headers
	${source_dir}/vnctpmd.h
	)
set(sources 					
	${source_dir}/vnctpmd.cpp
	)

PYTHON_ADD_MODULE(vnctpmd  ${headers} ${sources})
TARGET_include_directories(vnctpmd PUBLIC ${PYTHON_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(vnctpmd ${Boost_LIBRARIES} ${Boost_PY_LIBRARIES} ${PYTHON_LIBRARIES} ${CTPAPI_MD_LIBRARY}) 

add_custom_command(TARGET vnctpmd POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CTPAPI_LIB_DLL} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE})