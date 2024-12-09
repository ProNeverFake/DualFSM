#include "behaviortree_cpp/bt_factory.h"

//#define MANUAL_STATIC_LINKING
// #include "dual_arm_bt/dummy_nodes.h"
#include "dual_arm_bt/tree_map.cpp"
#include "dual_arm_bt/nodes.hpp"
#include "dual_arm_bt/robot_interface.hpp"


using namespace BT;

int main()
{
    BehaviorTreeFactory factory;

    auto global_bb = BT::Blackboard::create();
    auto maintree_bb = BT::Blackboard::create(global_bb);

    maintree_bb->set("do_not_wait", true);
    maintree_bb->set("water_poured", false);
    maintree_bb->set("cup_in_place", false);

    GripperInterface gripper;
    factory.registerSimpleAction("OpenGripper", [&](TreeNode&) { return gripper.open(); });
    factory.registerSimpleAction("CloseGripper",
                                [&](TreeNode&) { return gripper.close(); });

    factory.registerNodeType<Wait>("Wait");
    factory.registerNodeType<MoveNode>("MoveNode");
    factory.registerNodeType<Print>("Print");

    factory.registerBehaviorTreeFromText(tree_map);

    auto tree = factory.createTree("dual_arm", maintree_bb);

    printTreeRecursively(tree.rootNode());

  tree.tickWhileRunning();

  return 0;
}
