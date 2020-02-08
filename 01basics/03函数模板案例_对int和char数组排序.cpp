#include <iostream>
using namespace std;

template<class T>
void printArray(T* arr, int len){
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template<class T>
void _merge(T* arr, int start, int mid, int end){
    T aux[mid - start];
    for (int i = start; i < mid; i++)
        aux[i - start] = arr[i];
    for (int i = start, j = start, k = mid; i < end; i++){
        if (j<mid && aux[j-start]<=arr[k])
            arr[i] = aux[j++ - start];
        else if (k < end && arr[k] <= aux[j-start])
            arr[i] = arr[k++];
        else if (j >= mid)
            arr[i] = arr[k++];
        else
            arr[i] = aux[j++ - start];
    }
}

/**
 * [begin, end)
 * */
template<class T>
void _myMergeSort(T* arr, int begin, int end){
    if (begin >= end - 1)
        return;
    int mid = begin + (end - begin) / 2;
    _myMergeSort(arr, begin, mid);
    _myMergeSort(arr, mid, end);
    _merge(arr, begin, mid, end);
}

template<class T>
void myMergeSort(T* arr, int len){
    _myMergeSort(arr, 0, len);
}

int main(){

    // int arr[] = {88,  17, 32, 0, -6, 9,6,5,1,4, 10, 7, 3};
    char arr[] = {'c', 'e', 'a', 'z', 't', 'e' , 'f', 'o'};

    int len = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, len);
    myMergeSort(arr, len);
    printArray(arr, len);
    return 0;
}