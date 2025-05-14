cmake_minimum_required(VERSION 3.5)

# Agrega un ejecutable para las pruebas unitarias
add_executable(dao-file-test daotests.cpp)

# Vincula la biblioteca dateutils al ejecutable de prueba
target_link_libraries(dao-file-test PRIVATE dao-file gtest_main)

target_include_directories(dao-file-test PUBLIC ${CMAKE_SOURCE_DIR}/src)

add_test(NAME dao-file-test COMMAND dao-file-test)
