cmake_minimum_required(VERSION 3.14)
project(TreeView)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH /usr/lib/x86_64-linux-gnu/QT5/5.13.0/gcc_64/lib/cmake)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Core Quick Qml REQUIRED)

add_executable(TreeView main.cpp TreeItem.cpp TreeItem.h TreeModel.cpp TreeModel.h)

target_link_libraries(TreeView Qt5::Core Qt5::Quick Qt5::Qml)
