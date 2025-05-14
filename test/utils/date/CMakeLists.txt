cmake_minimum_required(VERSION 3.5)

# Agrega un ejecutable para las pruebas unitarias
add_executable(utils-date-test dateutilstest.cpp)

# Vincula la biblioteca dateutils al ejecutable de prueba
target_link_libraries(utils-date-test PRIVATE utils-date gtest_main)

target_include_directories(utils-date-test PUBLIC ${CMAKE_SOURCE_DIR}/src)
add_test(NAME utils-date-test COMMAND utils-date-test)
