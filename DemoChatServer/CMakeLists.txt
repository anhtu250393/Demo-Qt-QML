cmake_minimum_required(VERSION 3.16)

project(DemoChatServer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DemoChatServer main.cpp
    source/namedpipehandler.h source/namedpipehandler.cpp
    source/messageutils.cpp source/messageutils.h
)

include(GNUInstallDirs)
install(TARGETS DemoChatServer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
