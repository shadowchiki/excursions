cmake_minimum_required(VERSION 3.5)

add_library(
  utils-date SHARED
  dateutils.h
  dateutils.cpp
  datefilter.h
  datefilter.cpp
  startdatefilter.h
  startdatefilter.cpp
  datefilterfactory.h
  datefilterfactory.cpp
  betweendatefilter.h
  betweendatefilter.cpp
  enddatefilter.h
  enddatefilter.cpp)

target_include_directories(utils-date PUBLIC ${CMAKE_SOURCE_DIR}/src)
