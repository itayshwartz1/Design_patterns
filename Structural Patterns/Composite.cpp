#include "vector"
#include "string"
#include <list>
#include <iostream>
using namespace std;

class Component{
public:
    list<Component*> list;
    string name;
    Component(string name){
        this->name = name;
    }

    void add(Component *component){
        list.push_back(component);
    }

    void remove(Component *component){
        list.remove(component);
    }

    virtual void getChild(){}

    virtual void operation(){}

};

class Composite : public Component{
public:
    Composite(string name): Component(name){}
    virtual void getChild(){
        cout << name;
        for(auto &c: list){
            c->getChild();
        }
    }
    virtual void operation() override{}
};

class Leaf : public Component{
public:
    Leaf(string name): Component(name){}
    virtual void getChild(){
        cout << name;
    }
    virtual void operation() override{}
};

int main(){

    Composite c1("a");
    c1.add(new Composite("b"));
    c1.add(new Leaf("c"));

    return 0;
}