// Command is a behavioral design pattern that turns a request into a stand-alone object that contains all
// information about the request. This transformation lets you pass requests as a method arguments, *delay* or
// *queue* a request’s execution, and support *undoable* operations.

#include <iostream>
#include "list"
using namespace std;

class Tv{
public:
    bool on = false;
    int volume = 50;
};

class Command{
public:
    Tv* tv;
    Command(Tv* tv): tv(tv){}
    virtual void execute(){};
};

class TurnOn : public Command{
public:
    void execute() override {
        this->tv->on = true;
    }
    TurnOn(Tv* tv) : Command(tv){}
};

class TurnOff : public Command{
public:
    TurnOff(Tv* tv) : Command(tv){}
    void execute() override {
        this->tv->on = false;
    }
};

class IncreaceVol : public Command{
public:
    IncreaceVol(Tv* tv) : Command(tv){}
    void execute() override {
        this->tv->volume+=1;
    }
};

class DecreaceVol : public Command{
    DecreaceVol(Tv* tv) : Command(tv){}
    void execute() override {
        this->tv->volume-=1;
    }
};

class SlowRemote{
    list<Command*> commandList;
public:
    SlowRemote(){}
    void executeCommands(){
        for(auto & command: commandList){
            command->execute();
        }
    }
    void addCommand(Command* command){
        commandList.push_back(command);
    }
};

int main() {
    Tv *tv = new Tv();

    cout << "Tv before: " <<endl;
    cout << "is on: " << tv->on << endl;
    cout << "volume: " << tv->volume << endl << endl;

    SlowRemote* remote = new SlowRemote();
    remote->addCommand(new TurnOn(tv));
    remote->addCommand(new IncreaceVol(tv));
    remote->addCommand(new IncreaceVol(tv));
    remote->addCommand(new IncreaceVol(tv));
    remote->addCommand(new TurnOff(tv));
    remote->addCommand(new TurnOn(tv));
    
    // only now the commands are executing!
    remote->executeCommands();

    cout << "Tv after: " <<endl;
    cout << "is on: " << tv->on << endl;
    cout << "volume: " << tv->volume << endl;
    return 0;
}
