cmake_minimum_required(VERSION 3.21)

add_library(
  ui-console SHARED
  ./ConsoleView.hpp
  ./ConsoleView.cpp
  ./Console.cpp
  ./Console.hpp
  ./ExcursionMenu.cpp
  ./ExcursionMenu.hpp
  ./command/GetExcursionByDateCommand.cpp
  ./command/GetExcursionByDateCommand.hpp
  ./command/AddExcursionCommand.cpp
  ./command/AddExcursionCommand.hpp
  ./command/MenuCommand.cpp
  ./command/MenuCommand.hpp
  ./command/ExitMenuCommand.cpp
  ./command/ExitMenuCommand.hpp
  ./command/ExitCommand.cpp
  ./command/ExitCommand.hpp)

target_link_libraries(ui-console PUBLIC ui controller-excursion)

target_include_directories(
  ui-console
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PUBLIC ${CMAKE_SOURCE_DIR}/src)
