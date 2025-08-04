cmake_minimum_required(VERSION 3.21)

qt_add_qml_module(ui-qt-common
    URI common
    VERSION 1.0
    QML_FILES
      Body.qml
      Button.qml
      Header.qml
      MainMenu.qml
      ButtonMenu.qml
      ButtonMenuList.qml
      UserInfo.qml
      Style.qml
      resources/Add.qml
    OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/common
)

qt_add_resources(ui-qt-common
    PREFIX /resources
    FILES
resources/Account.svg
resources/Add.svg
resources/Close.svg
resources/Logout.svg
resources/Secure.svg
resources/dropdown.png
)

target_link_libraries(ui-qt-common
    PRIVATE Qt6::Quick
    PUBLIC ui-qt-excursion
)

target_include_directories(ui-qt-common PUBLIC ${CMAKE_SOURCE_DIR}/src)

include(GNUInstallDirs)
install(TARGETS ui-qt-common
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

