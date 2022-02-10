#include <iostream>
using namespace std;


class Singleton{
private:
    static Singleton* instance;
    static int i;
    Singleton(){
        cout << "From Builder";
        cout << i;
    };

public:
    static Singleton* getInstance(){
        if (!instance)
            instance = new Singleton();
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;



int main() {
    Singleton* singleton = Singleton::getInstance();
    Singleton* singleton1 = Singleton::getInstance();
}