cmake_minimum_required(VERSION 3.21)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Qml Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_qml_module(ui-qt SHARED
    URI main
    VERSION 1.0
    QML_FILES
        Main.qml
      Body.qml
      Header.qml
      MainMenu.qml
      ButtonMenu.qml
      ButtonMenuList.qml
      UserInfo.qml
    SOURCES
        QtView.cpp
        QtView.hpp
    OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/main
    PLUGIN_TARGET ui-qt
)

target_link_libraries(ui-qt
    PRIVATE Qt6::Quick
    PUBLIC ui
    PUBLIC ui-qt-excursion
    PUBLIC ui-qt-common
)

add_subdirectory(fa)
add_subdirectory(common)

include(GNUInstallDirs)
install(TARGETS ui-qt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_include_directories(ui-qt PUBLIC ${CMAKE_SOURCE_DIR}/src)
