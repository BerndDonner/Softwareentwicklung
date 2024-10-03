cmake_minimum_required(VERSION 3.16)

project(000hello_world LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(000hello_world main.cpp)

include(GNUInstallDirs)
install(TARGETS 000hello_world
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
