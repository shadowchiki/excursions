cmake_minimum_required(VERSION 3.21)

qt_add_qml_module(ui-qt-common
    URI common
    VERSION 1.0
    QML_FILES
        Button.qml
    OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/common
)

target_link_libraries(ui-qt-common
    PRIVATE Qt6::Quick
)

target_include_directories(ui-qt-common PUBLIC ${CMAKE_SOURCE_DIR}/src)

