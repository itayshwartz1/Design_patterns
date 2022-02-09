#include <iostream>
using namespace std;



class Color{
public:
    virtual string paint(){ return "";}
};

class Red : public Color{
public:
    virtual string paint() override{
        return "red";
    }
};

class Yellow : public Color{
public:
    virtual string paint() override{
        return "yellow";
    }
};

class House{
public:
    Color *color;
    House(Color *color) {
        this->color = color;
    }
    void paintHouse(){
        cout << color->paint() << endl;
    }
    virtual void BuildHouse(){}
};
class RoundHouse : public House{
public:
    RoundHouse(Color *color) : House(color){}
    virtual void BuildHouse() override{
        cout << "Round House in color: ";
        paintHouse();
    }
};

class TriangleHouse : public House{
public:
    TriangleHouse(Color *color) : House(color){}

    virtual void BuildHouse() override {
        cout << "Triangle House in color:";
        paintHouse();
    }
};

int main(){
    House* house = new RoundHouse( new Red());
    house->BuildHouse();
    return 0;
}