cmake_minimum_required(VERSION 3.21)

project(excursions)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_QML_GENERATE_QMLLS_INI ON)

add_executable(excursions main.cpp)

# target_link_libraries(excursions PUBLIC utils-date PUBLIC dao-file PUBLIC ui-console PUBLIC ui-qt)
target_link_libraries(excursions PUBLIC factory-config)

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
