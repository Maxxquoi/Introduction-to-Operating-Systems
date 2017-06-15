cmake_minimum_required(VERSION 3.7)
project(CProgrammingExamples)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ClockTicks.cpp
        CurrentLocalTime.cpp
        FunctionDiffTime.cpp
        LinkedList.cpp
        main.cpp
        MSWindowsTime.cpp
        PseudoRandomNumbers.cpp
        Strcat.cpp
        Strchr.cpp
        Strcmp.cpp
        Strcpy.cpp
        Strlen.cpp
        StrlwrAndStrupr.cpp
        Strstr.cpp
        TimeStructureWithmktime.cpp
        Timezones.cpp
        UnixOrPosixTime.cpp)

add_executable(CProgrammingExamples ${SOURCE_FILES})