// This pattern help us to maintain a hierarchical structure. Each component can contain Components or a Leafs. Leaf not contain anyone.
// The Component and the Leaf both inheritor from Component.

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

    void add(Component* component){
        list.push_back(component);
    }

    void remove(Component* &component){
        list.remove(component);
    }

    virtual void getChild() const = 0;

    virtual void operation() const= 0;

};

class Composite : public Component{
public:
    Composite(string name): Component(name){}
    virtual void getChild() const{
        cout << name << endl;
        for(auto &c: list){
            c->getChild();
        }
    }
    virtual void operation() const override {}
};

class Leaf : public Component{
public:
    Leaf(string name): Component(name){}
    virtual void getChild() const{
        cout << name << endl;
    }
    virtual void operation() const override {
        //do something
    }
};

int main(){

    Composite c1("a");
    c1.add(new Composite("b"));
    c1.add(new Leaf("c"));
    c1.getChild();

    return 0;
}
