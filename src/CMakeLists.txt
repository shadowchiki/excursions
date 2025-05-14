cmake_minimum_required(VERSION 3.5)

add_executable(excursions main.cpp)

target_link_libraries(excursions utils-date dao-file)

install(
  TARGETS excursions
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

add_subdirectory(controller)
add_subdirectory(dao)
add_subdirectory(model)
add_subdirectory(utils)
