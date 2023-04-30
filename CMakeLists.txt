cmake_minimum_required(VERSION 3.22.1)
project(NovaEngine VERSION 0.1.0)

add_library(nova SHARED
    ./src/display/Window.cpp
    ./src/display/XlibWindow.cpp
    ./src/Nova.cpp
    ./src/Node.cpp
)

set_target_properties(nova PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(nova PROPERTIES SOVERSION 0)
set_target_properties(nova PROPERTIES PUBLIC_HEADER "./src/Nova.hpp")

target_include_directories(nova PRIVATE src)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(nova PRIVATE Threads::Threads)

include(GNUInstallDirs)

install(TARGETS nova
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})