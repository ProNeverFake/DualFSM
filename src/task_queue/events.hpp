#include<tinyfsm.hpp>

struct CupInPlace : tinyfsm::Event{
    
};

struct NextMove : tinyfsm::Event{};

struct Retry : tinyfsm::Event{};
