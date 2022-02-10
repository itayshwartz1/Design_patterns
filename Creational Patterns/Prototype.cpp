#include <iostream>
using namespace std;

class Prototype {
public:
    virtual Prototype* clone() = 0;
};

class Sheep : public Prototype{
public:
    Sheep() {}
    Prototype* clone() override{
        cout << "MAAA! my name is dolly" << endl;
        return new Sheep();
    }
};

class HumenCell : public Prototype{
public:
    HumenCell() {}
    Prototype* clone() override{
        cout << "Hello im a clone cell" << endl;
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


