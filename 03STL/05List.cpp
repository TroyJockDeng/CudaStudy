#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//算法中的sort只支持可随机访问的容器
//list不支持随机访问

template<class T>
bool judge(T a, T b){
    return a < b;
}

//push_back pop_back
//push_front pop_front
//insert, clear, erase, remove(elem)

template<class T>
void printItem(T item){
    cout << item << " ";
}

void test01(){
    list<int> l(10, 1);
    list<int> l1(l);
    l = list<int>(5, 6);
    l1.push_back(13);
    l1.push_front(7);
    list<int>::iterator iter = l1.begin();
    iter++;
    l1.insert(iter, 3, 5);
    l1.remove(1);
    for_each(l1.begin(), l1.end(), printItem<int>);
    // l1.insert(l.begin()+1, 3, 6);
    cout << endl;

    l1.sort(judge<int>);
    for_each(l1.begin(), l1.end(), printItem<int>);
    cout << endl;

    l1.reverse();
    for_each(l1.begin(), l1.end(), printItem<int>);

}

int main(){
    test01();
    return 0;
}