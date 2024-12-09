cmake_minimum_required(VERSION 3.12)
project(bbworker)

# add_subdirectory(dual_arm_fsm)
add_subdirectory(dual_arm_bt)
set(SOURCE_FILES main.cpp)

add_executable(test_exe ${SOURCE_FILES})
target_link_libraries(test_exe behaviortree_cpp bt_sample_nodes dual_arm_bt)
install(TARGETS test_exe DESTINATION ${PROJECT_INSTALL_BIN_DIR})

add_executable(bbworker bbworker.cpp)
target_link_libraries(bbworker behaviortree_cpp bt_sample_nodes dual_arm_bt)
install(TARGETS bbworker DESTINATION ${PROJECT_INSTALL_BIN_DIR})


