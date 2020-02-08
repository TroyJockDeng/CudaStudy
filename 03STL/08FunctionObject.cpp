#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class Print{
public:

    Print(){
        num = 0;
    }

    void operator()(T val){
        this->num++;
        cout << val << " " << num << endl;
    }

public:
    int num;
};

int main(){
    // Print<int> print;
    // print(112);
    Print<int> print;
    vector<int> v;
    for (int i = 0; i < 10; i++)  
        v.push_back(rand()% 1000);
    Print<int> printRet = for_each(v.begin(), v.end(), print);
    cout << "num: " << print.num << endl;
    cout << "num: " << printRet.num << endl << endl;

    print(10);
    print(20);
    cout << "num: " << print.num << endl;
}