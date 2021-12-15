cmake_minimum_required(VERSION 3.16)
project(abc1)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)


include_directories(include)

add_executable(abc1
        include/Circle.h
        include/Container.h
        include/Enums.h
        include/Figure.h
        include/Point.h
        include/Rectangle.h
        include/Triangle.h
        src/Circle.cpp
        src/Container.cpp
        src/Figure.cpp
        src/Rectangle.cpp
        src/Triangle.cpp
        main.cpp)
