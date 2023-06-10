cmake_minimum_required(VERSION 3.16)

project(CLOWDER LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

qt_standard_project_setup()

include_directories(${Qt6Core_INCLUDE_DIRS}
                    ${Qt6Gui_INCLUDE_DIRS}
                    ${Qt6Widgets_INCLUDE_DIRS})

qt_add_executable(CLOWDER main.cpp snake.cpp window.cpp)

set_target_properties(CLOWDER PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(CLOWDER PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)