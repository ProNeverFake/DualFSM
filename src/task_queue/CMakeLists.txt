cmake_minimum_required(VERSION 3.12)
project(libdualarm CXX)

set(SOURCE_FILES
    task_queue.hpp
    # division.cpp
    events.hpp
    left_arm.hpp
    right_arm.hpp
)

add_library(libtaskqueue SHARED STATIC ${SOURCE_FILES})

install(TARGETS libtaskqueue DESTINATION ${DIVISIBLE_INSTALL_LIB_DIR})
# install(FILES ${SOURCE_FILES} DESTINATION ${PROJECT_INSTALL_INCLUDE_DIR})
