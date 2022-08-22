// The purpose of the design pattern is to create objects that share a uniform interface without knowing their 
// specific classes. For this we will save the constructors in some data structure.
//Apparently it was much simpler to make new and be done with the piece. But there are cases where this template
// is needed. Suppose there is a company with n types of employees and according to input from the user we create
// a new employee. The naive solution of the new will mean that we need n conditions. A faster solution is to have a
// hash table with all the creators and given the name of a worker type we will be able to reach the
// appropriate creator in O(1) time.

#include <map>
#include "string"
using namespace std;


class product {
public:
    product() {}
};

class productA : public product {
public:
    productA() : product() {}
};

class productB : public product {
public:
    productB() : product() {}
};

class productC : public product {
public:
    productC() : product() {}
};

class Creator{
public:
    Creator(){}
    virtual product* create() = 0;
};

class ConcreteCreatorA : public Creator{
public:
    ConcreteCreatorA():Creator(){}
    virtual product* create() override{
        return new productA();
    };
};

class ConcreteCreatorB : public Creator{
public:
    ConcreteCreatorB():Creator(){}
    virtual product* create() override{
        return new productB();
    };
};

class ConcreteCreatorC : public Creator{
public:
    ConcreteCreatorC():Creator(){}
    virtual product* create() override{
        return new productC();
    };
};

int main() {
    map<string,Creator*> map;
    map["A"] = new ConcreteCreatorA();
    map["B"] = new ConcreteCreatorB();
    map["C"] = new ConcreteCreatorC();

    product * productA = (map.find("A")->second->create());
    product * productB = (map.find("B")->second->create());
    product * productC = (map.find("C")->second->create());
}
