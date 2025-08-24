cmake_minimum_required(VERSION 3.21)

add_library(factory-qt SHARED ./ViewFactoryQt.cpp ./ViewFactoryQt.hpp)

target_link_libraries(factory-qt PUBLIC factory PUBLIC ui-qt)

target_include_directories(
 factory-qt
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PUBLIC ${CMAKE_SOURCE_DIR}/src)

