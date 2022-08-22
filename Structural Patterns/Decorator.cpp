// This pattern solves a combination of different behaviors for a base object.Without it, we need to create 2^n classes.
// We create base object (pizza) and the concrete object that derived from it (BigPizza, SmallPizza).
// After that we need to create decorator classes that inherit  from Component and hold component.
// Each concrete decorator (olives, onion cheese) inherit from it.

#include <iostream>
using namespace std;

//Component
class Pizza {
public:
    virtual void draw() const = 0;
};

//Concrete Component
class BigPizza : public Pizza {
public:
    BigPizza() {}
    void draw() const override {
        cout << "Big Pizza pizza with:" <<endl;
    }
};

class SmallPizza : public Pizza {
public:
    SmallPizza() {}
    void draw() const override {
        cout << "Small Pizza pizza with:" <<endl;
    }
};

//Decorator
class Extra : public Pizza {
public:
    Pizza *pizza;

    Extra(Pizza* &extraOnPizza) {
        pizza = extraOnPizza;
    }
    virtual void addBehavior()const {}
    void draw() const override {
        pizza->draw();
        addBehavior();
    }
};


class Olives : public Extra {
public:
    Olives(Pizza *extra) : Extra(extra){}

    virtual void addBehavior() {
        cout << "Olives" <<endl;
    }
};

class Onion : public Extra {
public:
    Onion(Pizza *extra) : Extra(extra){}

    virtual void addBehavior() const{
        cout << "Onion"<<endl;
    }
};

class Cheese : public Extra {
public:
    Cheese(Pizza *extra) : Extra(extra){}

    virtual void addBehavior() const {
        cout << "Cheese" <<endl;
    }
};

int main() {
    Pizza *pizza = new Olives(new Onion(new Cheese(new BigPizza())));
    pizza->draw();
    return 0;
}
