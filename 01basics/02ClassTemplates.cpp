#include <iostream>
using namespace std;

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

void test01(){
    //类模板必须显示指定类型;函数模板可以进行类型推断
    Person<int> p(10, 20);
    p.show();
}

int main(){
    test01();
}