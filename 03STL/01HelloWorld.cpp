#include <iostream>
#include <vector>
#include <algorithm>
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

template<class T>
void printPerson(Person<T> p){
    p.show();
}

void printVector(int v){
    cout << v << " ";
}

void test01(){
    vector<int> v;
    v.push_back(11);

    vector<int> v1({11, 12, 13});
    v1.push_back(14);

    //通过STL提供的for_each进行遍历
    // iterator is provided by container
    vector<int>::iterator pBegin = v1.begin();
    vector<int>::iterator pEnd = v1.end(); 

    for_each(pBegin, pEnd, printVector);
    cout << endl;
}

void test02(){
    vector<Person<int>> v;
    Person<int> p1(11, 12), p2(13, 14), p3(15, 16);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    for(vector<Person<int>>::iterator it = v.begin(); it != v.end(); it++)
        it->show();
    for_each(v.begin(), v.end(), printPerson<int>);

    cout << endl;
    v.back().show();
    v.front().show();
}

int main(){
    test01();
    test02();
    return 0;
}