cmake_minimum_required(VERSION 3.3)
project(mac2oui)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES lookup.cpp tests.cpp lookup.h)
add_executable(mac2oui ${SOURCE_FILES})

configure_file(oui_download.txt oui_download.txt COPYONLY)
configure_file(mac_config.txt mac_config.txt COPYONLY)