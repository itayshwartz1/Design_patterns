//
// Created by itay2 on 09/02/2022.
//
#include <iostream>
using namespace std;
#include "algorithm"
#include <vector>

class Employee{
public:
    int id;
    int age;
    string name;
    Employee(int id, int age, string name){
        this->id = id;
        this->age = age;
        this->name = name;
    }
    Employee(){}
};
class Comperator{
public:
    bool virtual compare(Employee &a, Employee &b);
};

class IdComperator{
    bool compare(Employee &a, Employee &b){
        return a.id>b.id;
    }
};

class NameComperator{
    bool compare(Employee &a, Employee &b){
        return a.name>b.name;
    }
};



class Sorter{
public:
    Employee *array;
    int size;
    Comperator comperator;
    Sorter(Employee *array, int size, Comperator comperator){
        this->array = array;
        this->size = size;
        this->comperator = comperator;
    }
    virtual void sort();
};

class BubbleSort: Sorter{
public:

    void sort() override{
        for (int i = 0; i < size-1; i++)
            for (int j = 0; j < size-i-1; j++)
                if (comperator.compare(array[j], array[j+1]))
                    swap(&array[j], &array[j+1]);
    }

    void swap(Employee *a, Employee *b){
        Employee temp = *a;
        *a = *b;
        *b = temp;
    }

};

class InsertionSort : Sorter{
    void sort() override{
        int  j;
        Employee key;
        for (int i = 1; i < size; i++)
        {
            key = array[i];
            j = i - 1;

            /* Move elements of arr[0..i-1], that are
            greater than key, to one position ahead
            of their current position */
            while (j >= 0 && comperator.compare(array[j] , key)){
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }
};

int main(){
    vector<int> vector = {1,2,3,5,7,898,1,5,3,2};

    return 0;
};