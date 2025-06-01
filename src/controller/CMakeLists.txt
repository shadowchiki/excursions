cmake_minimum_required(VERSION 3.5)

add_library(controller-excursion SHARED excursioncontroller.cpp excursioncontroller.h)

target_link_libraries(controller-excursion PUBLIC dao-file)

target_include_directories(controller-excursion PUBLIC ${CMAKE_SOURCE_DIR}/src)
