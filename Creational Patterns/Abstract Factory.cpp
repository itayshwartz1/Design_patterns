#include <iostream>
using namespace std;

class Product{
public:
    Product(){}
    virtual void functionality() = 0;
};

class Sword : public Product {
public:
    Sword() : Product(){}
};

class Shield : public Product {
public:
    Shield() : Product(){}
};

class Helmet : public Product {
public:
    Helmet() : Product(){}
};

class LightSaber : public Sword{
public:
    LightSaber() : Sword(){}
    virtual void functionality(){
        cout << "voom voom" << endl;
    };
};

class Deflector : public Shield{
public:
    Deflector() : Shield(){}
    virtual void functionality(){
        cout << "Deflector"<< endl;
    };
};
class MandalorianHelmet : public Helmet{
public:
    MandalorianHelmet() : Helmet(){}
    virtual void functionality(){
        cout << "Mandalorian Helmet"<< endl;
    };
};


class GimlyHelmet : public Helmet{
public:
    GimlyHelmet() : Helmet(){}
    virtual void functionality(){
        cout << "Gimly Helmet"<< endl;
    };
};

class AndurilSword : public Sword{
public:
    AndurilSword() : Sword(){}
    virtual void functionality(){
        cout << "Anduril Sword"<< endl;
    };
};

class RoundShield : public Shield{
public:
    RoundShield() : Shield(){}
    virtual void functionality(){
        cout << "Round Shield"<< endl;
    };
};


class AbstractFactory{
public:
    virtual Product* createSword() = 0;
    virtual Product* createShield() = 0;
    virtual Product* createHelmet() = 0;
};

class StarWarsFactory : public AbstractFactory{
public:
    Product* createSword(){
        return new LightSaber();
    };
    Product* createShield(){
        return new Deflector();
    };
    Product* createHelmet(){
        return new MandalorianHelmet();
    };
};

class LordOfTheRingsFactory : public AbstractFactory{
public:
    Product* createSword(){
        return new AndurilSword();
    };
    Product* createShield(){
        return new RoundShield();
    };
    Product* createHelmet(){
        return new GimlyHelmet();
    };
};


int main(){
    AbstractFactory* abstractFactory = new StarWarsFactory();

    Product *sword = abstractFactory->createSword();
    Product *shield = abstractFactory->createShield();
    Product *helmet = abstractFactory->createHelmet();

    sword->functionality();
    shield->functionality();
    helmet->functionality();

    abstractFactory = new LordOfTheRingsFactory();

    sword = abstractFactory->createSword();
    shield = abstractFactory->createShield();
    helmet = abstractFactory->createHelmet();

    sword->functionality();
    shield->functionality();
    helmet->functionality();
    return 0;
}

