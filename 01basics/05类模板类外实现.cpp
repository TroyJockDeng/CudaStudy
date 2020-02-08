#include <iostream>
using namespace std;

//不要滥用类外友元！！
template<class T> class Person;
template<class T> ostream& operator<<(ostream&, Person<T>&);
template<class T> void printPerson(Person<T>& );

template<class T>
class Person{
public:
    Person(T age, T id);

    //重载操作符, 类外定义友元，需要先声明
    friend ostream& operator<<<T>(ostream&, Person<T>&);
    friend void printPerson<T>(Person<T>& p);

    void show();
public:
    T mAge;
    T mId;  
};

template<class T>
Person<T>::Person(T age, T id){
    this->mAge = age;
    this->mId = id;
}

template<class T>
void Person<T>::show(){
    cout << "Age is " << mAge << ", Id is " << mId << endl;
}

template<class T>
ostream& operator<<(ostream& os, Person<T>& p){
    os << "Age is " << p.mAge << ", Id is " << p.mId << endl;
    return os;
} //重载操作符

template<class T>
void printPerson(Person<T>& p){
    cout << "Age is " << p.mAge << ", Id is " << p.mId << endl;
}


void test01(){
    Person<int> p(10, 20);
    p.show();
    cout << p;
    printPerson(p);
}

int main(){
    test01();
}

