cmake_minimum_required(VERSION 3.16)

project(010funktionen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(010funktionen main.cpp)

include(GNUInstallDirs)
install(TARGETS 010funktionen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
