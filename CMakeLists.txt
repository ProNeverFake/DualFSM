cmake_minimum_required(VERSION 3.14)

project(DualFSM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(PROJECT_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(PROJECT_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(DUAL_ARM_FSM_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/dual_arm_fsm)
# set(DIVISION_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/division)

include_directories(${PROJECT_INSTALL_INCLUDE_DIR})
include_directories(${DUAL_ARM_FSM_HEADERS_DIR})

find_package(ament_cmake QUIET)

if(ament_cmake_FOUND)

    find_package(behaviortree_cpp REQUIRED)
    ament_target_dependencies(btcpp_sample behaviortree_cpp)

elseif( CATKIN_DEVEL_PREFIX OR CATKIN_BUILD_BINARY_PACKAGE)

    find_package(catkin REQUIRED COMPONENTS behaviortree_cpp)
    catkin_package(CATKIN_DEPENDS behaviortree_cpp)
    target_include_directories(btcpp_sample PRIVATE ${catkin_INCLUDE_DIRS})
    target_link_libraries(btcpp_sample ${catkin_LIBRARIES})

else()

    find_package(behaviortree_cpp REQUIRED)
    # target_link_libraries(btcpp_sample BT::behaviortree_cpp)

endif()




add_subdirectory(include)
add_subdirectory(src)
# add_subdirectory(test)


