cmake_minimum_required(VERSION 3.16)

project(011funktion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(011funktion main.cpp)

include(GNUInstallDirs)
install(TARGETS 011funktion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
