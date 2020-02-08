#include <iostream>
using namespace std;

template<class T>
class MyArray{
public:
    MyArray(int capacity){
        mCapacity = capacity;
        mSize = 0;
        pAddr = new T[mCapacity];
    }

    MyArray(const MyArray& arr){ //copy-constructor
        this->mSize = arr.mSize;
        this->mCapacity = arr.mCapacity;
        this->pAddr = new T[this->mCapacity];
        for (int i = 0; i < this->mSize; i++)
            this->pAddr[i] = arr[i];
    }
    
    T& operator[](int index){
        return pAddr[index];
    }

    MyArray<T> operator=(const MyArray<T>& arr){
        if (!this->pAddr)
            delete[] this->pAddr;
        this->mSize = arr.mSize;
        this->mCapacity = arr.mCapacity;
        this->pAddr = new T[this->mCapacity];
        for (int i = 0; i < this->mSize; i++)
            this->pAddr[i] = arr[i];
        return *this;    
    }
  
    void pushBack(T& data){
        if(mSize>=mCapacity)
            return;
        pAddr[mSize++] = data;
    }

//**********************************
// &&对右值去引用！！！
    void pushBack1(T&& dat){
        if(mSize>=mCapacity)
            return;
        pAddr[mSize++] = dat;
    }

    ~MyArray(){
        if (!this->pAddr)
            delete[] this->pAddr;
    }
public:
    int mCapacity;
    int mSize;
    T* pAddr;
};

void test01(){
    MyArray<int> marray(20);
    int a = 10;
    marray.pushBack(a);
    a = 20;
    marray.pushBack(a);
    a = 30;
    marray.pushBack(a);

    marray.pushBack1(70);
    marray.pushBack1(100);


    for (int i = 0; i < marray.mSize; i++)
        cout << marray[i] << " ";
    cout << endl;
}


int main(){
    test01();
    return 0;
}