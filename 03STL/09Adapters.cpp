#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Print: public binary_function<int, int, void> {
public:
    void operator()(int v, int val) const{
        cout << v << ", " << val << " ";
        cout << v + val<< endl;
    }
};

void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    // for_each(v.begin(), v.end(), Print());
    //绑定适配器, bind2nd,将二元函数对象转为一元函数对象
    for_each(v.begin(), v.end(), bind2nd(Print(), 100));
    cout << endl;
    for_each(v.begin(), v.end(), bind1st(Print(), 100));


}

class Compare: public binary_function<int, int, bool>{
public:
    bool operator()(int v1, int v2) const{
        return v1 > v2;
    }
};

//not1 not2,取反适配器
void test02(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    sort(v.begin(), v.end(), Compare());
    for_each(v.begin(), v.end(), bind2nd(Print(), 100));
    cout << "shabi" << endl;
    sort(v.begin(), v.end(), not2(Compare()));
    for_each(v.begin(), v.end(), bind2nd(Print(), 100));

}


void printItemV(int val){
    cout << val << endl;
}

//仿函数适配器ptr_fun,把普通函数转为函数对象

//成员函数适配器, 若容器中存放的是对象， mem_func_ref(&ClassName::funcname)
//            ，若容器中存放对象指针， mem_func(&ClassName::funcname)
void test03(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    for_each(v.begin(), v.end(), printItemV);
    
}

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

    bool operator==(const Person<T>& p){
        return this->mId == p.mId && this->mAge == p.mAge;
    }
public:
    T   mAge;
    T   mId;
};


template<class T>
void printItem(T item){
    cout << item << " ";
}

//find algorithm
void test04(){
    cout << "test04" << endl;
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    auto ret = find(v.begin(), v.end(), 5);
    if(ret != v.end())
        cout << *ret << endl;
    else
        cout << "Not found!" << endl;

    Person<int> p1(10, 20), p2(20, 30), p3(11, 22);
    vector<Person<int>> v1;
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    for_each(v1.begin(), v1.end(), printItem<Person<int>>);

    auto pret = find(v1.begin(), v1.end(), Person<int>(10, 20));
    if (pret != v1.end())
        cout << "find result: " << *pret << endl;

    // transform()

}

int main(){
    test01();
    cout << endl;

    test02();
    cout << endl << "test03" << endl;
    test03();

    test04();
}
