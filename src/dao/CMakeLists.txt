cmake_minimum_required(VERSION 3.5)

add_library(dao-interface INTERFACE ExcursionDao.h FederationDao.h)

target_link_libraries(dao-interface INTERFACE model)

target_include_directories(dao-interface INTERFACE ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(file)
