// #include<states.hpp>
#include<tinyfsm.hpp>
#include<events.hpp>


/////////////////////////////
class LeftArm : public tinyfsm::Fsm<LeftArm>{
    public:
        virtual void react(CupInPlace const & event);
        virtual void react(NextMove const & event);
        virtual void react(Retry const & event);
        virtual void entry(void);
        virtual void exit(void);
};
////////////////////////////////

class Left1 : public LeftArm{
    public:
        void react(NextMove const & event) override;
        // void entry(void) override;
        // void exit(void) override;
};

class Left2 : public LeftArm{
    public:
        void react(NextMove const & event) override;


};

class Left3 : public LeftArm{
    public:
        void react(NextMove const & event) override;

};

class Left4 : public LeftArm{
    public:
        void react(NextMove const & event) override;


};

FSM_INITIAL_STATE(LeftArm, Left1);

