cmake_minimum_required(VERSION 3.21)

add_library(factory-config SHARED ./ConfFactory.cpp ./ConfFactory.hpp)

target_link_libraries(factory-config PUBLIC factory PUBLIC factory-console PUBLIC factory-qt)

target_include_directories(
 factory-config
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PUBLIC ${CMAKE_SOURCE_DIR}/src)

