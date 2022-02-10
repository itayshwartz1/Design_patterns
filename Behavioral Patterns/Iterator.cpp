#include "vector"
using namespace std;

class Iterator;
class TwoVectorIterator;
class TwoVector;

class Aggregate {
public:
    virtual Iterator* createIterator() = 0;
};

class Iterator {
    Aggregate * aggregate;
public:
    Iterator(){}
    virtual int* first() = 0;
    virtual int* next() = 0;
    virtual bool isDone() = 0;
    virtual int* currentItem() = 0;
};

class TwoVector : public Aggregate{
public:
    vector<int> firstVec;
    vector<int> secondVec;
    TwoVector(vector<int> first, vector<int> second) : firstVec(first), secondVec(second){}

    Iterator* createIterator() override{
        Iterator *iterator =  new TwoVectorIterator(this);
    }
};

class TwoVectorIterator : public Iterator {
    int firstIndex = 0;
    int secondIndex = 0;
    bool isFirst = true;

    int firstSize;
    int secondSize;
    TwoVector* twoVector;

public:
    TwoVectorIterator(TwoVector* twoVector) {
        firstSize = twoVector->firstVec.size();
        secondSize = twoVector->secondVec.size();
        this->twoVector = twoVector;
    }
    virtual int* first(){
        if(firstSize)
            return &this->twoVector->firstVec[0];
        return nullptr;
    };
    virtual int* next() {
        if (isDone()) {
            return nullptr;
        }
        if (isFirst){
            if(secondIndex < secondSize - 1){
                secondIndex++;
                return &twoVector->secondVec[secondIndex];
            }
            firstIndex++;
            return &twoVector->firstVec[firstIndex];
        }
        else{
            if(firstIndex < firstSize - 1){
                firstIndex++;
                return &twoVector->firstVec[firstIndex];
            }
            firstIndex++;
            return &twoVector->secondVec[secondIndex];
        }
    };
    virtual bool isDone(){
        return ((firstIndex == firstSize -1) && (secondIndex == secondSize -1));
    };

    virtual int* currentItem(){
        if (isFirst && firstSize > 0){
            return &twoVector->firstVec[firstIndex];
        }else if(!isFirst && secondSize > 0){
            return &twoVector->secondVec[secondIndex];
        }
        return nullptr;
    };

};

int main(){
    return 0;
}



