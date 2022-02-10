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

class CreatorA : public Creator{
public:
    CreatorA():Creator(){}
    virtual product* create() override{
        return new productA();
    };
};

class CreatorB : public Creator{
public:
    CreatorB():Creator(){}
    virtual product* create() override{
        return new productB();
    };
};

class CreatorC : public Creator{
public:
    CreatorC():Creator(){}
    virtual product* create() override{
        return new productC();
    };
};

int main() {
    map<string,Creator*> map;
    map["A"] = new CreatorA();
    map["B"] = new CreatorB();
    map["C"] = new CreatorC();

    product * productA = (map.find("A")->second->create());
    product * productB = (map.find("B")->second->create());
    product * productC = (map.find("C")->second->create());
}
