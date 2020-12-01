cmake_minimum_required(VERSION 3.5)

project(TSP-solver LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Threads)

if(ANDROID)
  add_library(TSP-solver SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    strategy.cpp
    strategy.h
    sa.h
    aco.h
    dynamicprogrammingalgorithm.h
    mainwindow.ui
    Graph.hpp
  )
else()
  add_executable(TSP-solver
    main.cpp
    mainwindow.cpp
    mainwindow.h
    strategy.cpp
    strategy.h
    sa.cpp
    sa.h
    aco.cpp
    aco.h
    pso.cpp
    pso.h
    dynamicprogrammingalgorithm.cpp
    dynamicprogrammingalgorithm.h
    mainwindow.ui
    Graph.hpp
  )
endif()

target_link_libraries(TSP-solver PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
