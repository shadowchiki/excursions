cmake_minimum_required(VERSION 3.21)

qt_add_qml_module(ui-qt-excursion SHARED
    URI excursion
    VERSION 1.0
    QML_FILES
        Excursion.qml
        ExcursionList.qml
        DateSelector.qml
    SOURCES
        ExcursionExecutable.cpp
        ExcursionExecutable.hpp
    OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/excursion
)

target_link_libraries(ui-qt-excursion
    PRIVATE Qt6::Quick
    PUBLIC controller-excursion
    PUBLIC ui-qt-common
)
set_target_properties(ui-qt-excursion PROPERTIES
    QT_QMLCACHEGEN_ARGUMENTS "--direct-calls"
)

target_include_directories(ui-qt-excursion PUBLIC ${CMAKE_SOURCE_DIR}/src)

include(GNUInstallDirs)
install(TARGETS ui-qt-excursion
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

