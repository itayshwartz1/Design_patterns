//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <vector>
//#include "thread"
//#include "mutex"
//
//using namespace std;
//
//class Employee {
//public:
//    int id;
//    int age;
//    string name;
//
//    Employee(int id, int age, string name) {
//        cout << "constructor" << endl;
//        this->id = id;
//        this->age = age;
//        this->name = name;
//    }
//
//    void operator()() {
//        age + 1;
//    }
//};
//
//
//class programmer : public Employee {
//public:
//    programmer(int id, int age, string name) : Employee(id, age, name) {}
//};
//
//template<typename T>
//bool max1(T a, T b) {
//    cout << " hello";
//    return a > b;
//}
//
//template<>
//bool max1(int a, int b) {
//    cout << " het!";
//    return a > b;
//}
//void sorter(int array[], f){
//    f(1,3);
//
//}
//
////int main() {
////    int array[] = {1,2,3};
////    sorter(array, [](int a, int b) {
////        return a>b;
////    });
////
////
////    return 0;
////}
//
//
