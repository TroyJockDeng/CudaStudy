#include <iostream>
#include <vector>
using namespace std;

void printVector(int v){
    cout << v << " ";
}

//使用swap收缩vector
void test01(){
    vector<int> v1(1000, 1);
    cout << "size: " << v1.size() << ", capacity: " << v1.capacity() << endl;
    v1.resize(10);
    cout << "size: " << v1.size() << ", capacity: " << v1.capacity() << endl;
    vector<int>(v1).swap(v1);
    cout << "size: " << v1.size() << ", capacity: " << v1.capacity() << endl;
}

//使用reserve预留空间
void test02(){
    vector<int> v1, v2;
    int* address;
    int num = 0;
    for (int i = 0; i < 10000; i++){
        v1.push_back(i);
        if (i != 0){
            if (address != &(v1[0])){
                num++;
                address = &(v1[0]);
            }
        }
    }
    cout << num << endl;

    v2.reserve(10000);
    num = 0;
    for (int i = 0; i < 10000; i++){
        v2.push_back(i);
        if (i != 0){
            if (address != &(v2[0])){
                num++;
                address = &(v2[0]);
            }
        }
    }
    cout << num << endl;

}

int main(){
    test01();
    test02();
    return 0;
}