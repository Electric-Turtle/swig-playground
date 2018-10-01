cmake_minimum_required(VERSION 3.12.2)
project(myswigproject)
include_directories(include)
add_library(mylibrary SHARED src/mylibrary.cpp)

add_executable(myexecutable src/myexecutable.cpp)
target_link_libraries(myexecutable mylibrary)

find_package(SWIG REQUIRED)
include(UseSWIG)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})


set_property(SOURCE include/mylibrary.i PROPERTY CPLUSPLUS ON)
SWIG_ADD_LIBRARY(py_mylibrary TYPE MODULE LANGUAGE python SOURCES include/mylibrary.i)
swig_link_libraries(py_mylibrary mylibrary)

