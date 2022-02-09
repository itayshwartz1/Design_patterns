#include <iostream>
using namespace std;
#include "algorithm"
#include <vector>


class Adaptee{
public:
    std::vector<int> vector;
    Adaptee(std::vector<int> vector){
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

//we use example that the adapter is some kind of sorting, and we want to do some specific task on the sorting.
//int main() {
//    Adaptee sorter = Adaptee({9,6,2,5,7,0,1,3,4,8});
//    Adapter adapter(sorter);
//    adapter.doSortAndRequest();
//    adapter.print();
//    return 0;
//}

