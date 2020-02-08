#include<iostream>
using namespace std;


//templates, ignore type.  严格的类型匹配，不允许自动类型转换
// 优先调用普通函数，普通函数不满足才调用模板;可通过<>，强行指定调用模板
//  let the compiler know the template
//  template<class T>
//  template<typename T>
template<class T>
void mySwap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}


int main(){
    int a = 1, b = 2;
    cout << "before swap, a: " << a << ", b: " << b << endl;
    // 1 automatic type inference
    mySwap(a, b);
    cout << "after swap, a: " << a << ", b: " << b << endl;

    // 2 specify the type
    cout << "before swap, a: " << a << ", b: " << b << endl;
    mySwap<int>(a, b);
    cout << "after swap, a: " << a << ", b: " << b << endl;

}