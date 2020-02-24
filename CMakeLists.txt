cmake_minimum_required(VERSION 3.15)
project(OS_Scheduler)

set(CMAKE_CXX_STANDARD 98)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(OS_Scheduler main.cpp task.h scheduler.h time.h
        time.cpp scheduler.cpp tasks/task_decorator.h tasks/task_decorator.cpp
        tasks/basic_task.h tasks/basic_task.cpp
        tasks/looping_task.h tasks/looping_task.cpp
        tasks/streaming_task.h tasks/streaming_task.cpp
        tasks/sleeping_task.h tasks/sleeping_task.cpp)
target_link_libraries(OS_Scheduler gtest gtest_main pthread)
