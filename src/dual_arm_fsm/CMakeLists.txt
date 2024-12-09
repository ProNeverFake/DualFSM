cmake_minimum_required(VERSION 3.12)
project(libdualarm CXX)

set(SOURCE_FILES
    states.hpp
    # division.cpp
    events.hpp
    left_arm.hpp
    right_arm.hpp
)

add_library(libdualarm SHARED STATIC ${SOURCE_FILES})

install(TARGETS libdualarm DESTINATION ${DIVISIBLE_INSTALL_LIB_DIR})
# install(FILES ${SOURCE_FILES} DESTINATION ${PROJECT_INSTALL_INCLUDE_DIR})
