cmake_minimum_required(VERSION 3.12.2)
project(myswigproject)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)
endif()

include_directories(include)
add_library(mylibrary SHARED src/mylibrary.cpp)
add_executable(myexecutable src/myexecutable.cpp)
target_link_libraries(myexecutable mylibrary)

find_package(SWIG REQUIRED)
include(UseSWIG)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})


set_property(SOURCE include/mylibrary.i PROPERTY CPLUSPLUS ON)
set_source_files_properties(include/mylibrary.i PROPERTIES SWIG_FLAGS "-includeall")
SWIG_ADD_LIBRARY(py_mylibrary TYPE MODULE LANGUAGE python SOURCES include/mylibrary.i)
swig_link_libraries(py_mylibrary mylibrary ${PYTHON_LIBRARIES})
#execute_process(COMMAND python -c "from distutils.sysconfig import get_python_lib; print(get_python_lib())" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
set(PYTHON_SITE_PACKAGES "Python/Lib/site-packages")
install(TARGETS myexecutable mylibrary
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
		)
install(TARGETS _py_mylibrary DESTINATION ${PYTHON_SITE_PACKAGES})
install(FILES ${CMAKE_BINARY_DIR}/py_mylibrary.py DESTINATION ${PYTHON_SITE_PACKAGES})
set(CPACK_GENERATOR NSIS)
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "T Dubs")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A toy example of usig SWIG")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${PROJECT_NAME})
set(CPACK_NSIS_MODIFY_PATH ON)

INCLUDE(CPack)