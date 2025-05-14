cmake_minimum_required(VERSION 3.5)

project(excursions LANGUAGES CXX)

#[[set crea variables a utilizar en el fichero]]
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

add_subdirectory(src)
add_subdirectory(test)

# Habilita el sistema de prueba
enable_testing()
