// The purpose of the design pattern is to reduce the number of objects we hold at a given time.
// We need to create Flyweight class and concrete Flyweight(Soldier, Tank, Airplane).
// Then we need Flyweight Factory - he is on charge who will create.
// If there is somw concrete flyweight that is alredy exist in the program, the factory should return pointer to
// the existing object. Otherwise he will create and return pointer to the new object.
// 

#include <iostream>
#include <list>
using namespace std;

class Flyweight{
public:
    string name;
    Flyweight(string name){ this->name = name;}
};

class Soldier : public Flyweight{
public:
    Soldier(string name) : Flyweight(name){}
};
class Tank : public Flyweight{
public:
    Tank(string name) : Flyweight(name){}
};
class Airplane : public Flyweight{
public:
    Airplane(string name) : Flyweight(name){}
};

class FlyweightFactory{
public:
    list<Flyweight> list;

    FlyweightFactory(){}

    Flyweight* getFlyweight(string flyweightName){
        for(auto& flyweight : list){
            if (flyweight.name == flyweightName){
                return &flyweight;
            }
        }
        if (flyweightName == "Soldier"){
            Soldier *soldier = new Soldier("Soldier");
            list.push_back(*soldier);
            return soldier;
        }
        if (flyweightName == "Tank"){
            Tank *tank = new Tank("Tank");
            list.push_back(*tank);
            return tank;
        }
        if (flyweightName == "Airplane"){
            Airplane *airplane = new Airplane("Airplane");
            list.push_back(*airplane);
            return airplane;
        }
    }

};

int main(){
    FlyweightFactory* flyweightFactory = new FlyweightFactory();
    Flyweight* soldier = flyweightFactory->getFlyweight("Soldier");
    Flyweight* soldier2 = flyweightFactory->getFlyweight("Soldier");
    Flyweight* soldier3 = flyweightFactory->getFlyweight("Soldier");

}
