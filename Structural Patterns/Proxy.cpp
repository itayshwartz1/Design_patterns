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
        if (it != cache.end())
            return it->second;
    }
};

class Proxy : Subject{
public:
    RealSubject* realSubject;
    Proxy(RealSubject *realSubject): Subject(){
        this->realSubject = realSubject;
    }

    string request(string query) override{
        map<string, string>::iterator it;
        it = cache.find(query);
        if (it != cache.end()) {
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
    Proxy *proxy = new Proxy(realSubject);
    string  s = proxy->request("How many days are there in a year");
    return 0;
}

