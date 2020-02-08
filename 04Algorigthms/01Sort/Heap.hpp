#ifndef HEAP
#define HEAP
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdexcept>

template<class T>
class Heap{

public:
    Heap(T arr[], int n){
        data.insert(data.begin(), arr, arr+n);
        heapify();
    }

    int size(){
        return data.size();
    }

    bool empty(){
        return data.empty();
    }

    void insert(T dat){
        data.push_back(dat);
        shiftUp(data.size()-1);
    }

    T extractMax(){
        if (data.empty())
            throw out_of_range("Empty heap!\n");
        swap(data[0], data[data.size()-1]);
        T top = data.back();
        data.pop_back();
        shiftDown(0);
        return top;
    }

    friend ostream& operator<<(ostream&, Heap<T>& heap){
        for (int i = 0; i < heap.size(); i++)
            cout << heap.data[i] << " ";
        cout << endl;
    }

private:
    vector<T> data;

    void shiftUp(int k){
        while (k != 0){
            if (data[(k-1)/2] < data[k]){
                swap(data[(k-1)/2], data[k]);
                k = (k - 1) / 2;    
            }
            else
                break;
        }
    }

    void shiftDown(int k){
        while(2 * k + 1 < data.size()){
            int j = 2 * k + 1;
            if ( 2 * k + 2 < data.size()){
                if (data[2 * k + 2] > data[2 * k + 1])
                    j++;
            }
            if (data[k] < data[j]){
                swap(data[k], data[j]);
                k = j;
            }else
                break;
        }
    }

    void heapify(){
        if(data.empty())
            return;
        for (int k = data.size() - 1; k > (k - 1) / 2; k--)
            shiftUp(k);
    }
};

#endif