#include <iostream>
using namespace std;

//类模板派生普通类
//TODO: not figured out yet
template<class T>
class Person{
public:
    Person(T id, T age){
        mAge = age;
        mId = id;
    }
    void show(){
        cout << "id: " << mId << ", age: " << mAge << endl;
    }

public:
    T mId;
    T mAge;
};

class SubPerson: public Person<int>{
};

//类模板派生模板类
//  派生类访问父类成员函数要用this
template<class T>
class Animal{
public:
    void bark(){
        cout << mAge << "-year-old animal is barking!" << endl;
    }
public:
    T mAge;
};

template<class T>
class Cat: public Animal<T>{
public:
    Cat(T age){
        this->mAge = age;
    }
};

void test01(){
    //类模板必须显示指定类型;函数模板可以进行类型推断
    Person<int> p(10, 20);
    p.show();

    Cat<int> cat(10);
    cat.bark();
}




int main(){
    test01();
}