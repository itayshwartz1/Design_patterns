// Observer is a behavioral design pattern that lets you define a subscription mechanism
// to notify multiple objects about any events that happen to the object they’re observing.

#include "vector"
#include "string"
#include <iostream>
using namespace std;

class Observer;
class Subject;


class Observer{
public:
    virtual void update(Subject* subject) = 0;
};


class Subject{
public:

    string state;
    string name;
    vector<Observer*> observers;

    Subject(string name): name(name){}

    string getState() const{
        return state;
    }
    void setState(string s){
        this->state = s;
    }

    string getName() const{
        return name;
    }

    void Attach(Observer* observer){
        observers.emplace_back(observer);
    };

    void Detach(Observer* observer){
        for (int i = 0; i < observers.size(); i++) {
            if (observer == observers[i]){
                observers.erase(observers.begin() + i);
                break;
            }
        }
    }

    void Notify(){
        for(auto & observer: observers){
            observer->update(this);
        }
    };

};

class TalentHunter : public Observer{
public:
    TalentHunter(){}
    void update(Subject* subject) {
        if(subject->getState() == "Three"){
            cout << "The Talent Hunter say: " << subject->getName() << " good job" << endl;
        }
    }
};

class Crowd : public Observer{
public:
    Crowd(){}
    void update(Subject* subject) {
        if(subject->getState() == "Slipped"){
            cout << "The Crowd say: OUUTCH " << subject->getName() << " slipped..." <<endl;
        }
        else {
            cout << "The Crowd say: WOWWWW" << endl;
        }
    }
};

class BobMother : public Observer{
public:
    BobMother(){}
    void update(Subject* subject) {
        if(subject->getName() == "Bob"){
            cout << "Bob mother say: That's my boy!" << endl;
        }

    }
};

class BasketBallPlayer : public Subject{
public:
    BasketBallPlayer(string name) : Subject(name){}
    void Functionality(){}
};

int main(){
    Observer* talentScouter = new TalentHunter();
    Observer* crowd = new Crowd();
    Observer* bobMother = new BobMother();

    Subject *bob = new BasketBallPlayer("Bob");
    Subject *alice = new BasketBallPlayer("Alice");

    bob->Attach(crowd);
    bob->Attach(bobMother);
    bob->Attach(talentScouter);

    alice->Attach(crowd);
    alice->Attach(bobMother);
    alice->Attach(talentScouter);


    cout << "bob score three! what everyone says?" << endl;
    bob->setState("Three");
    bob->Notify();
    cout << " " << endl;

    cout << "bob slipped! what everyone says?" << endl;
    bob->setState("Slipped");
    bob->Notify();
    cout << " " << endl;

    cout << "alice score three! what everyone says?" << endl;
    alice->setState("Three");
    alice->Notify();
    cout << " " << endl;


    cout << "bob score two! what everyone says?" << endl;
    alice->setState("Two");
    alice->Notify();


    return 0;
}

