#include<left_arm.hpp>

void Left1::react(NextMove const & event){
    transit<Left2>();
}


void Left2::react(NextMove const & event){
    transit<Left3>();
}


void Left3::react(NextMove const & event){
    transit<Left4>();
}
