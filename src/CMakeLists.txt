cmake_minimum_required(VERSION 3.2)
project(bbworker)

# add_subdirectory(division)
set(SOURCE_FILES main.cpp)

add_executable(worker ${SOURCE_FILES})
# target_link_libraries(divider division)
install(TARGETS worker DESTINATION ${PROJECT_INSTALL_BIN_DIR})
