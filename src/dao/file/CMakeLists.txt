cmake_minimum_required(VERSION 3.5)

add_library(
  dao-file SHARED
  ExcursionDaoFileImpl.cpp ExcursionDaoFileImpl.h FederationDaoFileImpl.cpp
  FederationDaoFileImpl.h FileDao.h FileDao.cpp)

target_link_libraries(
  dao-file
  PUBLIC dao-interface
  PUBLIC utils-date)

target_include_directories(dao-file PUBLIC ${CMAKE_SOURCE_DIR}/src)
