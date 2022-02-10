#include <iostream>
using namespace std;

class Instance {
    friend class Singleton;
    Instance(){
        cout << "From Builder";
    }
};

class Singleton{
    static Instance* instance;
public:
    static Instance* getInstance(){
        if (!instance)
            instance = new Instance();
        return instance;
    }
};
Instance* Singleton::instance = nullptr;



int main() {
    Instance* instance = Singleton::getInstance();
    instance = Singleton::getInstance();
}