#include "string"
#include <iostream>
using namespace std;


class State{
public:
    virtual void Handle() = 0;
};

class Helthy : public State {
public:
    Helthy(){}
    void Handle() override{
        cout << "walk" << endl;
    }
};

class Sick : public State {
public:
    Sick(){}
    void Handle() override{
        cout << "walk with crutches" << endl;
    }
};

class Robot{
public:
    State *state;
    Robot(State* state):state(state){}
    void setState(State* state){
        this->state = state;
    }
    void move(){
        this->state->Handle();
    }
};

int main(){
    Robot *robot = new Robot(new Helthy());
    robot->move();
    robot->setState(new Sick);
    robot->move();
    return 0;
}

