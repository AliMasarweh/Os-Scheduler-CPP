cmake_minimum_required(VERSION 3.15)
project(OS_Scheduler)

set(CMAKE_CXX_STANDARD 98)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(OS_Scheduler main.cpp task.h scheduler.h time.h
        time.cpp scheduler.cpp task_decorator.h task_decorator.cpp
        )
target_link_libraries(OS_Scheduler gtest gtest_main pthread)
