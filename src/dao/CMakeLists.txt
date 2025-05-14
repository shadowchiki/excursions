cmake_minimum_required(VERSION 3.5)

add_library(dao-interface excursiondao.h federationdao.h)

target_link_libraries(dao-interface PUBLIC model)

target_include_directories(dao-interface PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(file)
