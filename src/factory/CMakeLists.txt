cmake_minimum_required(VERSION 3.21)

add_library(factory INTERFACE ./ViewFactory.hpp)

target_link_libraries(factory INTERFACE ui)

target_include_directories(
 factory
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src
  INTERFACE ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(console)
add_subdirectory(qt)
add_subdirectory(config)
