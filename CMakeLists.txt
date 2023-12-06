cmake_minimum_required(VERSION 3.21)
project(FinalProject)

set(CMAKE_CXX_STANDARD 14)

find_package(Python REQUIRED COMPONENTS Development)

execute_process(
        COMMAND ${Python_EXECUTABLE} -c "import numpy; print(numpy.get_include())"
        OUTPUT_VARIABLE NumPy_INCLUDE_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Include directories for NumPy headers
include_directories(${Python_INCLUDE_DIRS} ${NumPy_INCLUDE_DIR})

add_definitions(-DWITHOUT_NUMPY)

add_executable(FinalProject main.cpp VGData.h
        MakeGraphs.cpp
        MakeGraphs.h
        MySetClass.cpp
        MySetClass.h)

target_include_directories(FinalProject PRIVATE ${Python_INCLUDE_DIRS})
target_link_libraries(FinalProject PRIVATE ${Python_LIBRARIES})
