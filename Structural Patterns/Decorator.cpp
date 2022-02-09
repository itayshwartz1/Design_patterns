#include <iostream>
using namespace std;

//Component
class Pizza {
public:
    virtual void draw() = 0;
};

//Concrete Component
class BigPizza : public Pizza {
public:
    BigPizza() {}
    void draw() override {
        cout << "Big Pizza pizza with: ";
    }
};

class SmallPizza : public Pizza {
public:
    SmallPizza() {}
    void draw() override {
        cout << "Small Pizza pizza with: ";
    }
};

//Decorator
class Extra : public Pizza {
public:
    Pizza *pizza;

    Extra(Pizza *extraOnPizza) {
        pizza = extraOnPizza;
    }
    virtual void addBehavior() {}
    void draw() override {
        pizza->draw();
        addBehavior();
    }
};


class Olives : public Extra {
public:
    Olives(Pizza *extra) : Extra(extra){}

    virtual void addBehavior() {
        cout << "Olives ";
    }
};

class Onion : public Extra {
public:
    Onion(Pizza *extra) : Extra(extra){}

    virtual void addBehavior() {
        cout << "Onion ";
    }
};

class Cheese : public Extra {
public:
    Cheese(Pizza *extra) : Extra(extra){}

    virtual void addBehavior() {
        cout << "Cheese ";
    }
};

int main() {
    Pizza *pizza = new Olives(new Onion(new Cheese(new BigPizza())));
    pizza->draw();
    return 0;
}





