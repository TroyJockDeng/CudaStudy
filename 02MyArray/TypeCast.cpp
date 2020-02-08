#include <iostream>
using namespace std;

class Building{};
class Animal{};
class Cat: public Animal{};

int main(){
    int a = 100;
    // char c = static_cast<char>(a);
    char c = a;
    cout << c;

/**************************************************************************/
//1. static_cast

//基础类型指针
    // int *p = NULL;
    // char *p1 = p;

//对象指针,fail
    // Building* building = NULL;
    // Animal* animal = static_cast<Animal*>(building);

//具有继承关系的对象指针
//父类转成子类    
    Animal* animal = NULL;
    Cat* cat = static_cast<Cat*>(animal);
//子类转成父类
    animal = cat;

//static_cast 用于基础数据类型，以及具有继承关系的指针、引用

/**************************************************************************/
//2. dynamic_cast,转换具有继承关系的指针或引用，转换前进行对象数据类型转换: Cat-->Animal,只能子类转父类
    int d = 10;

/**************************************************************************/
//3. const_cast, 指针、引用或对象指针, 取消或增加const
    int cc = 10;
    const int& bb = cc;
    int& ccc = const_cast<int&>(bb);
    ccc = 20;
    cout << ccc << " " << cc << " " << bb << endl;

/**************************************************************************/
//4. reinterpret_cast, 强制类型转换

}