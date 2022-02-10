#include <map>
#include "string"
#include <iterator>
#include <iostream>

using namespace std;

class Subject{
public:
    map<string, string> cache;
    Subject(){}
    virtual string request(string query) = 0;
};

class RealSubject : public Subject{
public:
    RealSubject(): Subject(){
        cache.insert(pair<string, string>("How many days are there in a year","365"));
        cache.insert(pair<string, string>("What is the distance from Earth to the Moon?","384,400"));
        cache.insert(pair<string, string>("How much is 3 + 10?","13"));
    }
    string request(string query) override{
        map<string ,string>::iterator it;
        it = cache.find(query);
        if (it != cache.end()) {
            cout << "frome RealSubject" << endl;
            return it->second;
        }
    }
};

class Proxy : public Subject{
public:
    RealSubject* realSubject;
    Proxy(RealSubject *realSubject): Subject(){
        this->realSubject = realSubject;
    }

    string request(string query) override{
        map<string, string>::iterator it;
        it = cache.find(query);
        if (it != cache.end()) {
            cout << "frome proxy" << endl;
            return it->second;
        }
        else{
            string s = realSubject->request(query);
            cache.insert(pair<string, string>(query, s));
            return s;
        }
    }
};

int main(){
    RealSubject* realSubject = new RealSubject;
    Subject *subject = new Proxy(realSubject);
    string  a = subject->request("What is the distance from Earth to the Moon?");
    string  b = subject->request("What is the distance from Earth to the Moon?");
    string  c = subject->request("How many days are there in a year");
    string  d = subject->request("How many days are there in a year");
    return 0;
}

