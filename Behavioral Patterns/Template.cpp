#include <iostream>
using namespace std;

class Employee{
public:
    int id, age;
    Employee(int id, int age) : id(id), age(age){}
};

class BubbleSort{
public:
    void swap(Employee *a, Employee *b){
        Employee temp = *a;
        *a = *b;
        *b = temp;
    }

    void bubbleSort(Employee arr[], int n){
        int i, j;
        for (i = 0; i < n-1; i++)

            for (j = 0; j < n-i-1; j++)
                if (compare(arr[j] , arr[j+1]))
                    swap(&arr[j], &arr[j+1]);
    }

    virtual bool compare(Employee &a, Employee& b) = 0;

    void printArr(Employee arr[], int n){
        for(int i = 0; i < n; i++){
            cout << "ID: " << arr[i].id << " Age: " << arr[i].age << endl;
        }
        cout << endl;
    }
};

class BubbleSortByAge : public BubbleSort{
public:
    BubbleSortByAge(){};
    bool compare(Employee &a, Employee &b) override {
        return a.age > b.age;
    }
};

class BubbleSortById : public BubbleSort{
public:
    BubbleSortById(){};
    bool compare(Employee &a, Employee &b) override {
        return a.id > b.id;
    }
};


int main(){
    Employee array[] = {Employee(5,20),Employee(2,50),Employee(3,40),Employee(6,15),Employee(9,80),Employee(1,25) };
    BubbleSortByAge *bubbleSortByAge = new BubbleSortByAge();
    bubbleSortByAge->bubbleSort(array, 6);
    bubbleSortByAge->printArr(array, 6);

    BubbleSortById* bubbleSortById = new BubbleSortById();
    bubbleSortById->bubbleSort(array, 6);
    bubbleSortById->printArr(array, 6);
    return 0;
}

