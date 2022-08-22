//This design pattern helps us to duplicate objects of the interface type without knowing what the specific type of
// the object is. Everyone will implement the cloning method
#include <iostream>
using namespace std;

class Prototype {
public:
    virtual Prototype* clone() const = 0;
};

class Sheep : public Prototype{
public:
    Sheep() {}
    Prototype* clone() const override{
        cout << "MAAA! my name is dolly!" << endl;
        return new Sheep();
    }
};

class HumenCell : public Prototype{
public:
    HumenCell() {}
    Prototype* clone() const override{
        cout << "Hello im a clone cell!" << endl;
        return new HumenCell();
    }
};

int main(){
    Prototype* firstSheep = new Sheep();
    Prototype* secondSheep = firstSheep->clone();

    Prototype* firstCell = new HumenCell();
    Prototype* secondCell = firstCell->clone();
    return 0;
}
