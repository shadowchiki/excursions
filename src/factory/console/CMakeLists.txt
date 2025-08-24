cmake_minimum_required(VERSION 3.21)

add_library(factory-console SHARED ./ViewFactoryConsole.cpp ./ViewFactoryConsole.hpp)

target_link_libraries(factory-console PUBLIC factory PUBLIC ui-console)

target_include_directories(
 factory-console
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PUBLIC ${CMAKE_SOURCE_DIR}/src)

