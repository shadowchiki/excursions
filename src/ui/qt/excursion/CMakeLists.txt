cmake_minimum_required(VERSION 3.21)

qt_add_qml_module(ui-qt-excursion
    URI excursion
    VERSION 1.0
    QML_FILES
        Excursion.qml
    SOURCES
        ExcursionExecutable.cpp
        ExcursionExecutable.hpp
    OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/excursion
)

target_link_libraries(ui-qt-excursion
    PRIVATE Qt6::Quick
    PUBLIC controller-excursion
)
set_target_properties(ui-qt-excursion PROPERTIES
    QT_QMLCACHEGEN_ARGUMENTS "--direct-calls"
)

target_include_directories(ui-qt-excursion PUBLIC ${CMAKE_SOURCE_DIR}/src)

