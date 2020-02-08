#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;
//异常跨函数，异常必须处理
class Person{
public:
    Person(){
        cout << "constructor" << endl;
    }
    ~Person(){
        cout << "deconstrcutor" << endl;
    }
};

int divide(int x, int y){
    Person p1, p2;
    if (y == 0){
        // throw y; //throw exception
        throw out_of_range("divider out of range!");
    }
    return x / y;
}

class MyOutOfRange : public out_of_range{
public:
    MyOutOfRange(char* err){
        pError = new char[strlen(err) + 1];
        strcpy(pError, err);
    }

    ~MyOutOfRange(){
        if (!pError)
            delete[] pError;
    }

    virtual const char * what() const{
        return pError;
    }

public:
    char* pError;
};


void test01(){
    divide(10, 0);
}

int main(){
//抛出异常时，try块内的内存会自动析构
    try{
        test01();
    }catch(out_of_range e){
        cout << e.what() << endl;
    }catch(...){
        cout << "unknown exception" << endl;
    }
}