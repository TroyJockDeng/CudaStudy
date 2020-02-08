#include <iostream>
#include <deque>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

//deque
//插入删除只有这四个 
//push_back pop_back
//push_front pop_front
//随机读取，效率高
//两端插删，效率高

template<class T>
void printItem(T item){
    cout << item << " ";
}

// deque
void test01(){
    deque<int> d(10, 2);
    deque<int> d1;
    vector<int> v(10, 1);

    for_each(d.begin(), d.end(), printItem<int>);
    cout << endl;

    d1.assign(d.begin(), d.end());
    for_each(d1.begin(), d1.end(), printItem<int>);
    cout << endl;
    
    deque<int> d3;
    d3 = d;

}

//stack
//不能遍历，不支持随机读取，只能通过top访问栈顶
//不提供迭代器
//push
void test02(){
    stack<int> s;
    stack<int> s1(s);
    s1.push(10);
    s1.push(20);
    while(!s1.empty()){
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
}

//queue
//不能遍历，不支持随机读取,只能通过back, front访问
//不提供迭代器
//push pop
void test03(){
    queue<int> q;
    q.push(11);
    q.push(10);
    q.push(9);
    queue<int> q1(q);
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


int main(){
    test01();
    test02();
    test03();
}