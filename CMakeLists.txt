cmake_minimum_required(VERSION 3.5)

project(excursions LANGUAGES CXX)

#[[set crea variables a utilizar en el fichero]]
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#[[
    Añade al ejecutable las clases necesarias para compilar
]]
add_executable(${PROJECT_NAME} main.cpp
    model/excursion.h model/excursion.cpp
    model/partner/partner.h model/partner/partner.cpp
    model/partner/standarpartner.h model/partner/standarpartner.cpp
    model/partner/federatedpartner.h model/partner/federatedpartner.cpp
    model/partner/childrenpartner.h model/partner/childrenpartner.cpp
    model/secure.h model/secure.cpp
    model/federation.h model/federation.cpp
    model/inscription.h model/inscription.cpp
    controller/excursioncontroller.h controller/excursioncontroller.cpp
    filedb/excursions.txt
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

add_subdirectory(utils/date/)
add_subdirectory(utils/date/test)
add_subdirectory(controller/dao/)
add_subdirectory(controller/dao/test)
target_link_libraries(${PROJECT_NAME} dateutils dao)

#[[Crea funciones a ejecutar en el fichero
EL primer valor es el nombre del metodo y el siguiente es un parametro
]]
function(methodName param)
    message("${${param}}")
endfunction()

#[[ejecuta la funcion creada previamente]]
methodName(PROJECT_NAME)
