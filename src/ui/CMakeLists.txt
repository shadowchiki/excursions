cmake_minimum_required(VERSION 3.21)

add_library(ui SHARED ./View.hpp ./Menu.hpp ./Command.hpp ./Command.cpp)

target_include_directories(
  ui
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(console)
add_subdirectory(qt)
