#include<chrono>
#include<behaviortree_cpp/action_node.h>
// #include<behaviortree_cpp/behavior_tree.h>
using namespace std::chrono;
using BT::NodeStatus;

// struct TreeBase {
//     std::shared_ptr<GlobalState> _global_state;
//     std::mutex& _global_state_mutex;

//     // Add a constructor that takes references to GlobalState and mutex
//     TreeBase(std::shared_ptr<GlobalState> global_state, std::mutex& global_state_mutex)
//         : _global_state(global_state), _global_state_mutex(global_state_mutex)
//     {}
// };
// Example of Asynchronous node that uses StatefulActionNode as base class

class Print : public BT::SyncActionNode
{
public:
  Print(const std::string& name, const BT::NodeConfig& config) :
      BT::SyncActionNode(name, config)
  {}

   static BT::PortsList providedPorts()
    {
      return {BT::InputPort<bool>("water_poured")};
      // return {};
      // return {BT::InputPort<bool>("water_poured"), BT::InputPort<bool>("cup_in_place"), BT::InputPort<bool>("do_not_wait")};
    }

  // You must override the virtual function tick()
  BT::NodeStatus tick() override
  {
    bool water_poured = getInput<bool>("water_poured").value();
    // bool cup_in_place = getInput<bool>("cup_in_place").value();
    // bool do_not_wait = getInput<bool>("do_not_wait").value();
    std::cout << "water_poured: " << water_poured << std::endl;
    // std::cout << "cup_in_place: " << cup_in_place << std::endl;
    // std::cout << "do_not_wait: " << do_not_wait << std::endl;
    return BT::NodeStatus::SUCCESS;
  }
};

class MoveNode : public BT::StatefulActionNode
{
  public:
    MoveNode(const std::string& name, const BT::NodeConfig& config)
      : BT::StatefulActionNode(name, config)
      // , TreeBase(global_state, global_state_mutex)
    {}

    static BT::PortsList providedPorts()
    {
      // amount of milliseconds that we want to sleep
      return {};
    }

    NodeStatus onStart() override
    {
        std::cout << "Move started:" << this->name() << std::endl;
        // once the deadline is reached, we will return SUCCESS.
        deadline_ = system_clock::now() + milliseconds(1000);
        return NodeStatus::RUNNING;
    }

    /// method invoked by an action in the RUNNING state.
    NodeStatus onRunning() override
    {
      if ( system_clock::now() >= deadline_ ) {
        std::cout << "Move done: " << this->name() << std::endl;
        return NodeStatus::SUCCESS;
      }
      else {
        // std::cout << "Moving: " << this->name() << std::endl;
        return NodeStatus::RUNNING;
      }
    }

    void onHalted() override
    {
      // nothing to do here...
      std::cout << "MoveNode interrupted" << std::endl;
    }

  private:
    system_clock::time_point deadline_;
};

class Wait : public BT::StatefulActionNode
{
  public:
    Wait(const std::string& name, const BT::NodeConfig& config)
      : BT::StatefulActionNode(name, config)
    {}

    static BT::PortsList providedPorts()
    {
      // return {InputPort<std::string>("check")};
      return {};
    }

    NodeStatus onStart() override
    {
        std::cout << "Start waiting for " << this->name() << std::endl;
        return NodeStatus::RUNNING;
    }

    NodeStatus onRunning() override
    {
        // _check = getInput<std::string>("check").value();
        // std::cout << "Waiting for the condition" << this->name() << std::endl;
        return NodeStatus::RUNNING;
    }

    void onHalted() override
    {
      // nothing to do here...
      std::cout << "MoveNode interrupted" << std::endl;
    }

  private:
    // std::string _check;
};