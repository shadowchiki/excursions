cmake_minimum_required(VERSION 3.5)

add_library(controller excursioncontroller.cpp excursioncontroller.h)

target_link_libraries(controller PUBLIC dao-file)

target_include_directories(controller PUBLIC ${CMAKE_SOURCE_DIR}/src)
