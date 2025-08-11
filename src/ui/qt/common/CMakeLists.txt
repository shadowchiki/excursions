cmake_minimum_required(VERSION 3.21)

set_source_files_properties(Style.qml PROPERTIES QT_QML_SINGLETON_TYPE TRUE)

qt_add_qml_module(ui-qt-common
    URI common
    VERSION 1.0
    QML_FILES
      Button.qml
      Style.qml
        TextBlock.qml
        Shadow.qml
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
)

target_include_directories(ui-qt-common PUBLIC ${CMAKE_SOURCE_DIR}/src)

include(GNUInstallDirs)
install(TARGETS ui-qt-common
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

