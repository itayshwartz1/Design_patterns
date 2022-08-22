//State is a behavioral design pattern that lets an object alter its behavior when its internal state changes.
// It appears as if the object changed its class.

#include "string"
#include <iostream>
using namespace std;

class State{
public:
    virtual void  Handle() const = 0;
};

class Healthy : public State {
public:
    void Handle() const override{
        cout << "Walk" << endl;
    }
};

class Sick : public State {
public:
    void Handle() const override{
        cout << "Walk with crutches" << endl;
    }
};

class Robot{
public:
    State *state;
    Robot(State* state):state(state){}
    void setState(State* state){
        this->state = state;
    }
    void move() const{
        this->state->Handle();
    }
};

int main(){
    auto *robot = new Robot(new Healthy());
    robot->move();
    robot->setState(new Sick);
    robot->move();
    return 0;
}

