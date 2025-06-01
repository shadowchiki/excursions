cmake_minimum_required(VERSION 3.5)

project(excursions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(excursions main.cpp)

target_link_libraries(excursions utils-date dao-file ui-console)

install(
  TARGETS excursions
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

target_include_directories(
 excursions 
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PUBLIC ${CMAKE_SOURCE_DIR}/src)

# Habilita el sistema de prueba
enable_testing()

add_subdirectory(src)
add_subdirectory(test)
