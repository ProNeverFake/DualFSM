#include<right_arm.hpp>

void Right1::react(NextMove const & event){
    transit<Right2>();
}


void Right2::react(CupInPlace const & event){
    transit<Right3>();
}


void Right3::react(NextMove const & event){
    transit<Right4>();
}
