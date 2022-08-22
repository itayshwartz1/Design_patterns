//The abstract factory pattern provides a way to encapsulate a group of individual factories that have
// a common theme without specifying their concrete classes. In normal usage, the client software creates a concrete
// implementation of the abstract factory and then uses the generic interface of the factory to create the concrete
// objects that are part of the theme. The client does not know (or care) which concrete objects it gets from each
// of these internal factories, since it uses only the generic interfaces of their products. This pattern separates
// the details of implementation of a set of objects from their general usage and relies on object composition, as
// object creation is implemented in methods exposed in the factory interface.

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
    void functionality() override{
        cout << "voom voom" << endl;
    };
};

class Deflector : public Shield{
public:
    Deflector() : Shield(){}
    void functionality() override{
        cout << "Deflector"<< endl;
    };
};
class MandalorianHelmet : public Helmet{
public:
    MandalorianHelmet() : Helmet(){}
    void functionality() override{
        cout << "Mandalorian Helmet"<< endl;
    };
};


class GimlyHelmet : public Helmet{
public:
    GimlyHelmet() : Helmet(){}
    void functionality() override{
        cout << "Gimly Helmet"<< endl;
    };
};

class AndurilSword : public Sword{
public:
    AndurilSword() : Sword(){}
    void functionality() override{
        cout << "Anduril Sword"<< endl;
    };
};

class RoundShield : public Shield{
public:
    RoundShield() : Shield(){}
    void functionality() override{
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
    Product* createSword() override{
        return new LightSaber();
    };
    Product* createShield() override{
        return new Deflector();
    };
    Product* createHelmet() override{
        return new MandalorianHelmet();
    };
};

class LordOfTheRingsFactory : public AbstractFactory{
public:
    Product* createSword() override{
        return new AndurilSword();
    };
    Product* createShield() override{
        return new RoundShield();
    };
    Product* createHelmet() override{
        return new GimlyHelmet();
    };
};


int main(){
    AbstractFactory* abstractFactory = new StarWarsFactory();

    Product *sword = abstractFactory->createSword();
    Product *shield = abstractFactory->createShield();
    Product *helmet = abstractFactory->createHelmet();


    cout<< "Star Wars:" << endl;
    sword->functionality();
    shield->functionality();
    helmet->functionality();

    cout<< "--------------------" << endl;

    abstractFactory = new LordOfTheRingsFactory();

    cout<< "Lord Of The Rings:" << endl;

    sword = abstractFactory->createSword();
    shield = abstractFactory->createShield();
    helmet = abstractFactory->createHelmet();

    sword->functionality();
    shield->functionality();
    helmet->functionality();
    return 0;
}
