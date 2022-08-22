// The purpose of this design pattern is to control access to another object for various purposes.
// We create a kind of mediator so that the requests don't have to reach the appropriate object.
// It may be that the broker can answer our question in a faster time (for example by using cache memory). 
// In addition, the broker can prevent certain queries, etc...

#include <map>
#include "string"
#include <iostream>

using namespace std;

class Subject{
public:
    map<string, string> cache;
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
    Proxy(RealSubject *realSubject): realSubject(realSubject){}

    string request(string query) override{
        map<string, string>::iterator it;
        it = cache.find(query);
        if (it != cache.end()) {
            cout << "from proxy" << endl;
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
    Subject *subject = new Proxy(new RealSubject);
    string  a = subject->request("What is the distance from Earth to the Moon?");   //from RealSubject
    string  b = subject->request("What is the distance from Earth to the Moon?");   //from proxy
    string  c = subject->request("How many days are there in a year");              //from RealSubject
    string  d = subject->request("How many days are there in a year");              //from proxy
    return 0;
}

