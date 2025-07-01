#[[
cmake_minimum_required(VERSION 3.10)            # Specify the minimum version of CMake
project(SimpleVulkanGame_C С)                   # Define the project name and specify the language

add_subdirectory(src)
include_directories(../include)                 # Include the header files
# Add an executable target
add_executable(MyExecutable main.c)             # Create an executable from main.c
set(CMAKE_C_COMPILER_ENV_VAR "MY_CC")
export(MY_CC=:/usr/bin/gcc)

]]
    # set required version
    cmake_minimum_required(VERSION 3.28.3)
    # set compiler
    set(CMAKE_C_COMPILER gcc)
     # set project name
    project(SimpleVulkanGame_C C)

    # set build options
    # set(CMAKE_CXX_FLAGS "-g")# debug mode
    set(CMAKE_C_FLAGS "-g")# debug mode
    # set(CMAKE_CXX_FLAGS "-O2 -march=native -std=c++11 -Wall")# release mode

    # set include directories
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

    #[[
    # generate shared libraries
    add_library(viete     SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/viete.cpp    ) 
    add_library(ramanujan SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/ramanujan.cpp) 
    add_library(gregory   SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/gregory.cpp  )

    # generate a static library
    add_library(factorial STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/factorial.cpp)
    ]]

    # generate executables
    add_executable(SimpleVulkanGame_C ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)

    # link libraries
    # target_link_libraries(calcpi viete ramanujan gregory factorial)
