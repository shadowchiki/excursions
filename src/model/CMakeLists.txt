cmake_minimum_required(VERSION 3.5)

add_library(
  model SHARED
  ./excursion.cpp
  ./excursion.h
  ./federation.cpp
  ./federation.h
  ./inscription.cpp
  ./inscription.h
  ./partner/childrenpartner.cpp
  ./partner/childrenpartner.h
  ./partner/federatedpartner.cpp
  ./partner/federatedpartner.h
  ./partner/partner.cpp
  ./partner/partner.h
  ./partner/standarpartner.cpp
  ./partner/standarpartner.h
  ./secure.cpp
  ./secure.h)

target_include_directories(model PUBLIC ${CMAKE_SOURCE_DIR}/src)
