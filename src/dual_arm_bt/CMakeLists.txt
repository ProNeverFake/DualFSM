add_library(bt_sample_nodes STATIC
    dummy_nodes.h
    dummy_nodes.cpp
)

target_link_libraries(bt_sample_nodes behaviortree_cpp)

add_library(dual_arm_bt STATIC
    tree_root.cpp
    tree_map.cpp
    nodes.hpp
    robot_interface.hpp
)

target_link_libraries(dual_arm_bt behaviortree_cpp)
