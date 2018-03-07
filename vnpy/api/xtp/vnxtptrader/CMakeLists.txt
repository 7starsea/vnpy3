
set(source_dir ${CMAKE_CURRENT_SOURCE_DIR})

set(headers
	${source_dir}/vnxtptrader.h
	)
set(sources 					
	${source_dir}/vnxtptrader.cpp
	)

PYTHON_ADD_MODULE(vnxtptrader  ${headers} ${sources})
TARGET_include_directories(vnxtptrader PUBLIC ${PYTHON_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(vnxtptrader ${Boost_LIBRARIES} ${Boost_PY_LIBRARIES} ${PYTHON_LIBRARIES} ${XTPAPI_TD_LIBRARY}) 

