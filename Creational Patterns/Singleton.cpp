//Singleton is a creational design pattern that lets you ensure that a class has only one instance,
// while providing a global access point to this instance.

#include <iostream>
using namespace std;

class Instance {
    friend class Singleton;
    Instance(){
        cout << "From Builder" <<endl;
    }
};

// static make the Instance create one time and don't die.
class Singleton{
    static Instance* instance;
public:
    static Instance* getInstance(){
        if (!instance)
            instance = new Instance();
        else{
            cout << "Do you come here a lot? It seems that the Instance has already been initialized" <<endl;
        }
        return instance;
    }
};
Instance* Singleton::instance = nullptr;



int main() {
    Instance* instance1 = Singleton::getInstance();
    Instance* instance2 = Singleton::getInstance();
    Instance* instance3 = Singleton::getInstance();
    Instance* instance4 = Singleton::getInstance();
}
