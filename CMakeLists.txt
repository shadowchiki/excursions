cmake_minimum_required(VERSION 3.5)

project(excursions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(excursions main.cpp
    model/excursion.h model/excursion.cpp
    model/partner/partner.h model/partner/partner.cpp
    model/partner/standarpartner.h model/partner/standarpartner.cpp
    model/partner/federatedpartner.h model/partner/federatedpartner.cpp
    model/partner/childrenpartner.h model/partner/childrenpartner.cpp
    model/secure/secure.h model/secure/secure.cpp
    model/federation.h model/federation.cpp
    model/inscription.h model/inscription.cpp
    controller/excursioncontroller.h controller/excursioncontroller.cpp
    controller/dao/excursiondao.h controller/dao/excursiondao.cpp
    controller/dao/impl/excursiondaoimpl.cpp
    controller/dao/impl/excursiondaofileimpl.h
)

include(GNUInstallDirs)
install(TARGETS excursions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
