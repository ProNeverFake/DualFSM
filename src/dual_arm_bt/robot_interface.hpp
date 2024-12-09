#include<behaviortree_cpp/behavior_tree.h>
using BT::NodeStatus;

class GripperInterface
{
public:
  GripperInterface() : _opened(true)
  {}

  NodeStatus open(){
    _opened = true;
    return NodeStatus::SUCCESS;
  };

  NodeStatus close(){
    _opened = false;
    return NodeStatus::SUCCESS;
  };

private:
  bool _opened;
};

std::mutex global_state_mtx;

struct GlobalState{
    bool water_poured = false;
    bool cup_in_place = false;
    bool do_not_wait = true;
};