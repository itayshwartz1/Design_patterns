#include <iostream>
#include "list"
using namespace std;

class Enemy{
public:
    Enemy()= default;
    virtual void print() = 0;
};

class Guard : public Enemy{
public:
    Guard()= default;
    virtual void print(){
        cout << "Guard" << endl;
    };
};

class KoopaTroopas : public Enemy{
public:
    KoopaTroopas()= default;
    virtual void print(){
        cout << "Koopa Troopas" << endl;
    };
};

class Character{
public:
    Character()= default;
    virtual void print() = 0;
};

class Aladdin : public Character{
public:
    Aladdin()= default;
    virtual void print(){
        cout << "Aladdin" << endl;
    };
};

class Mario : public Character{
public:
    Mario()= default;
    virtual void print(){
        cout << "Mario" << endl;
    };
};

class Jafar : public Character{
public:
    Jafar()= default;
    virtual void print(){
        cout << "Jafar" << endl;
    };
};

class KingKoopa : public Character{
public:
    KingKoopa()= default;
    virtual void print(){
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
    virtual void creatCharacter() override {
        this->level->character = new Aladdin();
    };
    virtual void creatBoss() override {
        this->level->boss = new Jafar();
    };
    virtual void creatEnemy() override {
        this->level->enemyList.push_back(new Guard());
    };
public:
    AladdinLevelBulder() : LevelBuilder(){}
};

class MarioLevelBulder : public LevelBuilder {
    virtual void creatCharacter() override {
        this->level->character = new Mario();
    };
    virtual void creatBoss() override {
        this->level->boss = new KingKoopa();
    };
    virtual void creatEnemy() override {
        this->level->enemyList.push_back(new KoopaTroopas());
    };
public:
    MarioLevelBulder() : LevelBuilder(){}
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
    Director* expert = new ExpertLevel(new MarioLevelBulder());
    expert->construct();
    expert->start();

    Director* boss = new BossLevel(new AladdinLevelBulder());
    boss->construct();
    boss->start();

    return 0;
}

