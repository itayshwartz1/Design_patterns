// Builder is a creation design pattern that lets you construct complex objects step by step.
// The pattern allows you to produce different types and representations of an object using the same construction code.

#include <iostream>
#include "list"
using namespace std;

class Enemy{
public:
    Enemy()= default;
    virtual void print() const= 0;
};

class Guard : public Enemy{
public:
    Guard()= default;
    virtual void print() const{
        cout << "Guard" << endl;
    };
};

class KoopaTroopas : public Enemy{
public:
    KoopaTroopas()= default;
    virtual void print() const{
        cout << "Koopa Troopas" << endl;
    };
};

class Character{
public:
    Character()= default;
    virtual void print() const= 0;
};

class Aladdin : public Character{
public:
    Aladdin()= default;
    virtual void print() const{
        cout << "Aladdin" << endl;
    };
};

class Mario : public Character{
public:
    Mario()= default;
    virtual void print() const{
        cout << "Mario" << endl;
    };
};

class Jafar : public Character{
public:
    Jafar()= default;
    virtual void print() const{
        cout << "Jafar" << endl;
    };
};

class KingKoopa : public Character{
public:
    KingKoopa()= default;
    virtual void print() const{
        cout << "King Koopa" << endl;
    };
};

class Level {
public:
    list<Enemy*> enemyList;
    Character *character = nullptr ;
    Character *boss = nullptr;
    Level(){}
};

class LevelBuilder {
public:
    Level* level;
    LevelBuilder(){
        this->level=new Level();
    }
    virtual void creatCharacter() {};
    virtual void creatBoss() = 0;
    virtual void creatEnemy() = 0;
};


class AladdinLevelBulder : public LevelBuilder {
    void creatCharacter() override {
        this->level->character = new Aladdin();
    };
    void creatBoss() override {
        this->level->boss = new Jafar();
    };
    void creatEnemy() override {
        this->level->enemyList.push_back(new Guard());
    };
};

class MarioLevelBuilder : public LevelBuilder {
    void creatCharacter() override {
        this->level->character = new Mario();
    };
    void creatBoss() override {
        this->level->boss = new KingKoopa();
    };
    void creatEnemy() override {
        this->level->enemyList.push_back(new KoopaTroopas());
    };
};

class Director{
public:
    LevelBuilder* levelBuilder;

    Director(LevelBuilder* levelBuilder){
        this->levelBuilder = levelBuilder;
    }
    virtual void construct() = 0;
    void start(){
        cout << "the main character is: ";
        levelBuilder->level->character->print();

        cout << "the enemies are: "<<endl;
        for(auto & enemy : levelBuilder->level->enemyList){
            enemy->print();
        }

        cout << "the boss is: ";
        if( levelBuilder->level->boss != nullptr)
            levelBuilder->level->boss->print();
        else{
            cout << "non" << endl;
        }
        cout << endl;
    }
};

class NoobLevel : public Director{
public:
    NoobLevel(LevelBuilder* levelBuilder) : Director(levelBuilder){}
    virtual void construct() override{
        levelBuilder->creatCharacter();
        levelBuilder->creatEnemy();
    }
};

class ExpertLevel : public Director{
public:
    ExpertLevel(LevelBuilder* levelBuilder) : Director(levelBuilder){}
    virtual void construct() override{
        levelBuilder->creatCharacter();

        levelBuilder->creatEnemy();
        levelBuilder->creatEnemy();
        levelBuilder->creatEnemy();

    }
};

class BossLevel : public Director{
public:
    BossLevel(LevelBuilder* levelBuilder) : Director(levelBuilder){}
    virtual void construct() override{
        levelBuilder->creatCharacter();

        levelBuilder->creatEnemy();
        levelBuilder->creatEnemy();
        levelBuilder->creatEnemy();
        levelBuilder->creatEnemy();
        levelBuilder->creatEnemy();

        levelBuilder->creatBoss();

    }
};

int main(){
    Director* expert = new ExpertLevel(new MarioLevelBuilder());
    expert->construct();
    expert->start();

    Director* boss = new BossLevel(new AladdinLevelBulder());
    boss->construct();
    boss->start();

    return 0;
}
