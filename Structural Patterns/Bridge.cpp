// We use this pattern when we need אם combine capabilities of one interface with another.
// In this example we have some kind of houses. Now we want to add them colors. The naive way is to create classes of all the options, But we want to avoid
// code duplicate, so we create Colore class and some colors thet extand it. The next step is to create House class and Houses that extand it, and the house class contain
// color as a member. Now instead of creating classes from all the compromises we can create n colors and m types of houses and by injection we can build all the 
// compromises from them (instead N*M classes).


#include <iostream>
using namespace std;

class Color{
public:
    virtual string paint() const{ return "";}
};

class Red : public Color{
public:
    virtual string paint() const override{
        return "red";
    }
};

class Yellow : public Color{
public:
    virtual string paint() const override{
        return "yellow";
    }
};

class House{
public:
    Color *color;
    House(Color* color) : color(color){}
    
    void paintHouse() const{
        cout << color->paint() << endl;
    }
    virtual void BuildHouse() const{}
};

class RoundHouse : public House{
public:
    RoundHouse(Color* color) : House(color){}
    
    virtual void BuildHouse() const override{
        cout << "Round House in color: ";
        paintHouse();
    }
};

class TriangleHouse : public House{
public:
    TriangleHouse(Color *color) : House(color){}

    virtual void BuildHouse() const  override {
        cout << "Triangle House in color:";
        paintHouse();
    }
};

int main(){
    House* house = new RoundHouse( new Red());
    house->BuildHouse();
    return 0;
}
