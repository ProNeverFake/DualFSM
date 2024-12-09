// #include<states.hpp>
#include<tinyfsm.hpp>
#include<events.hpp>


/////////////////////////////
class RightArm : public tinyfsm::Fsm<RightArm>{
    public:
        virtual void react(CupInPlace const & event){};
        virtual void react(NextMove const & event){
            // go to the next step here.
        };
        virtual void react(Retry const & event){
            // stop the current action and start a new action here
        };
        virtual void entry(void);
        virtual void exit(void);
};
////////////////////////////////

class Right1 : public RightArm{
    public:
        void react(NextMove const & event) override;
        // void entry(void) override;
        // void exit(void) override;
};

class Right2 : public RightArm{
    public:
        // void react(NextMove const & event) override;
        void react(CupInPlace const & event) override;

};

class Right3 : public RightArm{
    public:
        void react(NextMove const & event) override;

};

class Right4 : public RightArm{
    public:
        void react(NextMove const & event) override;


};

FSM_INITIAL_STATE(RightArm, Right1);

