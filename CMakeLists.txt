cmake_minimum_required(VERSION 3.15)
project(Epignosi)

set(CMAKE_CXX_STANDARD 20)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(Epignosi src/main.cpp)
