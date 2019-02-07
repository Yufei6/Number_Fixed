cmake_minimum_required(VERSION 3.0)
project(fixed)

find_package(Threads)

set(CMAKE_CXX_STANDARD 14)

add_executable(testfp
        testfp.cpp
        googletest/googletest/src/gtest-all.cc
        fixed.cpp fixed.h)

target_include_directories(testfp
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest"
        )

target_link_libraries(testfp
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
        )

add_executable(fixed main.cpp fixed.cpp fixed.h)