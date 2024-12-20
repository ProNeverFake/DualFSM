#include "behaviortree_cpp/bt_factory.h"

//#define MANUAL_STATIC_LINKING
#include "dual_arm_bt/dummy_nodes.h"


using namespace BT;

/** Behavior Tree are used to create a logic to decide what
 * to "do" and when. For this reason, our main building blocks are
 * Actions and Conditions.
 *
 * In this tutorial, we will learn how to create custom ActionNodes.
 * It is important to remember that NodeTree are just a way to
 * invoke callbacks (called tick() ). These callbacks are implemented by the user.
 */

// clang-format off
static const char* xml_text = R"(

 <root BTCPP_format="4" >

     <BehaviorTree ID="MainTree">
        <Sequence name="root_sequence">
            <CheckBattery   name="battery_ok"/>
            <OpenGripper    name="open_gripper"/>
            <ApproachObject name="approach_object"/>
            <CloseGripper   name="close_gripper"/>
        </Sequence>
     </BehaviorTree>

 </root>
 )";

// clang-format on

int main()
{
  // We use the BehaviorTreeFactory to register our custom nodes
  BehaviorTreeFactory factory;

  /* There are two ways to register nodes:
    *    - statically, i.e. registering all the nodes one by one.
    *    - dynamically, loading the TreeNodes from a shared library (plugin).
    * */

  // Note: the name used to register should be the same used in the XML.
  // Note that the same operations could be done using DummyNodes::RegisterNodes(factory)

  using namespace DummyNodes;

  auto global_bb = BT::Blackboard::create();
  auto maintree_bb = BT::Blackboard::create(global_bb);

  // The recommended way to create a Node is through inheritance.
  // Even if it requires more boilerplate, it allows you to use more functionalities
  // like ports (we will discuss this in future tutorials).
  factory.registerNodeType<ApproachObject>("ApproachObject");

  // Registering a SimpleActionNode using a function pointer.
  // you may also use C++11 lambdas instead of std::bind
  factory.registerSimpleCondition("CheckBattery",
                                  [&](TreeNode&) { return CheckBattery(); });

  //You can also create SimpleActionNodes using methods of a class
  GripperInterface gripper;
  factory.registerSimpleAction("OpenGripper", [&](TreeNode&) { return gripper.open(); });
  factory.registerSimpleAction("CloseGripper",
                               [&](TreeNode&) { return gripper.close(); });



  // Trees are created at deployment-time (i.e. at run-time, but only once at the beginning).
  // The currently supported format is XML.
  // IMPORTANT: when the object "tree" goes out of scope, all the TreeNodes are destroyed
  auto tree = factory.createTreeFromText(xml_text, maintree_bb);

  // To "execute" a Tree you need to "tick" it.
  // The tick is propagated to the children based on the logic of the tree.
  // In this case, the entire sequence is executed, because all the children
  // of the Sequence return SUCCESS.
  tree.tickWhileRunning();

  return 0;
}

/* Expected output:
*
       [ Battery: OK ]
       GripperInterface::open
       ApproachObject: approach_object
       GripperInterface::close
*/