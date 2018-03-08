# # Set path for boost and python
set(BOOST_ROOT "C:/Boost")	
set(PYTHON_INCLUDE_DIR "F:/Anaconda3/include")

# # auto set VNPY_API_XTP_WIN using CMAKE_SIZEOF_VOID_P (=4 for 32bit or =8 for 64bit)
math(EXPR VNPY_API_XTP_WIN "${CMAKE_SIZEOF_VOID_P} * 8")
# # set(VNPY_API_XTP_WIN 32)  # 64 if you set 64, please make sure CMAKE_SIZEOF_VOID_P=8

