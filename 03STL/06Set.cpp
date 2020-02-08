#include<iostream>
#include<set>
#include <algorithm>
using namespace std;
//set multiset
// insert erase erase(elem) clear
//find
//lower_bound upper_bound equal_bound
//提供迭代器，不能通过迭代器改变其值
//
template<class T>
void printItem(T item){
    cout << item << " ";
}

template<class T>
bool judge(T a, T b){
    return a < b;
}


// template<class T> class Person;
// template<class T> ostream& operator<<(ostream& os, Person<T>& p);

template<class T>
class Person{
public:
    Person(T id, T age){
        this->mId = id;
        this->mAge = age;
    }

    friend ostream& operator<<(ostream& os, Person<T>& p){
        os << "Id is " << p.mId << ", Age is " << p.mAge << endl;
        return os;
    }
public:
    T   mAge;
    T   mId;
};

//仿函数
template<class T>
class mycompare{
public:
    bool operator()(T v1, T v2){
        return v1 > v2;
    }
};

//仿函数
template<class T>
class personCompare{
public:
    bool operator()(Person<T> v1, Person<T> v2){
        return v1.mAge > v2.mAge;
    }
};

void test01(){
    set<int, mycompare<int>> s;//自动进行排序
    s.insert(7);
    s.insert(2);
    s.insert(1);
    s.insert(3);

    for_each(s.begin(), s.end(), printItem<int>);
    cout << endl;

    //erase
    set<int, mycompare<int>> s1(s);
    s1.erase(s1.begin(), ++++s1.begin());
    for_each(s1.begin(), s1.end(), printItem<int>);
    cout << endl;

    auto x = s.find(3);
    cout << *x << endl;

    int key = 4;
    auto y = s.lower_bound(key);
    if (y!=s.end())
        cout << "lower_bound: " << *y << endl;
    auto z = s.upper_bound(key);
    if (z!=s.end())
        cout << "upper_bound: " << *z << endl;

// equal_range, return lower_bound and upper_bound
//pair
//1. pair<T,T>(..., ...)
//2. make_pair(..., ...)
//3. =
    pair<set<int>::iterator, set<int>::iterator> p = s.equal_range(key);
    if (p.first!=s.end())
        cout << "lower_bound: " << *p.first << endl;
    if (p.second!=s.end())
        cout << "upper_bound: " << *p.second << endl;

    p.second = s.begin();
    cout << *p.second << endl;

    Person<int> person(10, 20);
    cout << person << endl;

    set<Person<int>, personCompare<int>> s2;
    Person<int> p1(10, 20), p2(20, 30), p3(5, 6), p4(-11, 77), p5(3, 9);
    s2.insert(p1);
    s2.insert(p2);
    s2.insert(p3);
    s2.insert(p4);
    s2.insert(p5);
    for_each(s2.begin(), s2.end(), printItem<Person<int>>);
    cout << endl;
    p3.mId = 888;
    for_each(s2.begin(), s2.end(), printItem<Person<int>>);

}

        
int main(){
    test01();
}