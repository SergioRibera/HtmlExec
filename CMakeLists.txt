cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
SET(appName HtmlExc)
include_directories("./WebView")
include_directories("./source")

add_executable (HtmlExc main.cpp)
TARGET_LINK_LIBRARIES(${appName})
