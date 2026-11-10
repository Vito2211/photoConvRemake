cmake_minimum_required(VERSION 3.10)
project(photoConvRemake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(photoConvRemake
    main.cpp
    jpeg_parser.cpp
)
