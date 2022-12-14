cmake_minimum_required(VERSION 3.16)

project(ThreadChart LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

find_package(Qt5 COMPONENTS Core Widgets Charts REQUIRED)
find_package(Qt5Charts REQUIRED)

set(SOURCES
    main.cpp
    mainwindow.cpp
    chartview.cpp
    customthread.cpp
    )

set(HEADERS
    mainwindow.h
    chartview.h
    customthread.h
    )

set(DISTFILES
    resources.qrc
    .gitignore
    )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${DISTFILES})

target_link_libraries(ThreadChart PUBLIC
    Qt5::Charts
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets)
