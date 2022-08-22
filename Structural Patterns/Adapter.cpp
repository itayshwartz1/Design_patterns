// We use this pattern when we need to adapt between one object to another. 
// what we need to do is to create class "Adapter" thet *contain* the "Adaptee" and *inherit* "Task". 
// If we make it inherit from Adaptee then for each combination of them we will have to open a new class
// In this the adapter is some kind of sorting, and we want to do some specific task with the sorting. 

#include <iostream>
#include "algorithm"
#include <vector>

using namespace std;

class Adaptee{
public:
    std::vector<int> vector;
    Adaptee(std::vector<int> &vector){
        this->vector = vector;
    }
    Adaptee(){}

    void sort() {
        std::sort(vector.begin(), vector.end());
        cout << "Adaptee working - sorting" <<endl;
    }
    void print(){
        for (auto &item: vector){
            cout << item;
        }
        cout <<endl;
    }
};

class Task{
public:
    Task(){}
    virtual void TaskPrintWhenFinished() {
        cout << "finish" <<endl ;
    }
};

class Adapter : public Task{
    Adaptee adaptee;
public:
    Adapter(Adaptee adaptee){
        this->adaptee = adaptee;
    }

    void doSortAndRequest() {
        adaptee.sort();
        TaskPrintWhenFinished();
    }

    void print() {
        adaptee.print();
        TaskPrintWhenFinished();
    }
};

int main() {
    Adaptee sorter = Adaptee({9,6,2,5,7,0,1,3,4,8});
    Adapter adapter(sorter);
    adapter.doSortAndRequest();
    adapter.print();
    return 0;
}

