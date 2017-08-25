cmake_minimum_required(VERSION 3.7)
project(turing)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES src/main.c src/turing.h src/turing.c src/doublylinkedlist.c src/doublylinkedlist.h)
add_executable(turing ${SOURCE_FILES})