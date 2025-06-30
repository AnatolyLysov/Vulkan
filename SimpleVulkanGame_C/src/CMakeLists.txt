cmake_minimum_required(VERSION 3.10)            # Specify the minimum version of CMake
project(SimpleVulkanGame_C С)                   # Define the project name and specify the language

add_subdirectory(src)
include_directories(../include)                 # Include the header files
# Add an executable target
add_executable(MyExecutable main.c)             # Create an executable from main.c
set(CMAKE_C_COMPILER_ENV_VAR "MY_CC")
export(MY_CC=:/usr/bin/gcc)

