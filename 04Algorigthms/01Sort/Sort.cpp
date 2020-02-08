#include <iostream>
#include <algorithm>
#include "SortHelper.hpp"
#include "Heap.hpp"

using namespace std;

#pragma region InsertionSort
// [begin, end)
template<class T>
void _insertionSort(T arr[], int begin, int end){
    for (int i = begin + 1; i < end; i++){
        T temp = arr[i];
        int j;
        for (j = i; j > 0 && temp < arr[j-1]; j--)
            arr[j] = arr[j-1];
        arr[j] = temp;
    }
}

template<class T>
void insertionSort(T arr[], int n){
    for (int i = 1; i < n; i++){
        T temp = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] >= temp; j--){
            arr[j+1] = arr[j];
        }
        if (j != i - 1)
            arr[j+1] = temp;
    }
}
#pragma endregion

#pragma region MergeSort
template<class T>
void _merge(T arr[], int begin, int mid, int end){
    T aux[mid - begin];
    for (int i = begin; i < mid; i++)
        aux[i - begin] = arr[i];
    for (int i = begin, j = begin, k = mid; i < end; i++){
        if (j < mid && aux[j-begin] <= arr[k])
            arr[i] = aux[j++ - begin];
        else if (k < end && arr[k] <= aux[j-begin])
            arr[i] = arr[k++];
        else if (j >= mid)
            arr[i] = arr[k++];
        else
            arr[i] = aux[j++ - begin];
    }
}

// sort [begin, end)
template<class T>
void _mergeSort(T arr[], int begin, int end){
    if (end - begin <= 1)
        return;
    int mid = begin + (end - begin) / 2;
    _mergeSort(arr, begin, mid);
    _mergeSort(arr, mid, end);
    _merge<T>(arr, begin, mid, end);
}

template<class T>
void mergeSort(T arr[], int n){
    _mergeSort<T>(arr, 0, n);
}
#pragma endregion

#pragma region MergeSortUpdate
template<class T>
void _mergeSortUpdate(T arr[], int begin, int end){
    if (end - begin <= 15){
        _insertionSort<T>(arr, begin, end);
        return;
    }
    int mid = begin + (end - begin) / 2;
    _mergeSort(arr, begin, mid);
    _mergeSort(arr, mid, end);
    _merge<T>(arr, begin, mid, end);
}

template<class T>
void mergeSortUpdate(T arr[], int n){
    _mergeSortUpdate<T>(arr, 0, n);
}
#pragma endregion

#pragma region  MergeSortBtmup
template<class T>
void mergeSortBtmup(T arr[], int n){
    for(int i = 1; i < n; i *= 2){
        for (int j = 0; j + i < n; j += 2 * i)
            _merge(arr, j, j + i, min(j + 2 * i , n));
    }
}
#pragma endregion

#pragma region QuickSort





template<class T>
int partition(T arr[], int begin, int end){
    T temp = arr[begin];
    int i = begin;
    for (int j = begin+1; j < end; j++){
        if (arr[j] < temp)
            swap<T>(arr[++i], arr[j]);
    }
    swap<T>(arr[begin], arr[i]);
    return i;
}

// [begin, end)
template<class T>
void _quickSort(T arr[], int begin, int end){
    if (end - begin <= 1)
        return;
    int mid = partition(arr, begin, end);
    _quickSort(arr, begin, mid);
    _quickSort(arr, mid + 1, end);
}

template<class T>
void quickSort(T arr[], int n){
    _quickSort(arr, 0, n);
}
#pragma endregion

#pragma region HeapSort
template<class T>
void shiftup(T arr[], int n, int p){
    assert(p < n);
    while((p-1)/2>=0){
        if(arr[p] > arr[(p-1)/2]){
            swap(arr[p], arr[(p-1)/2]);
            p = (p - 1) / 2;
        }else
            break;
    }
}

template<class T>
void shiftdown(T arr[], int n, int p){
    while(2 * p + 1 < n){
        int j = p * 2 + 1;
        if (j + 1< n){
            if (arr[j+1] > arr[j])
                j++;
        }
        if (arr[p] < arr[j]){
            swap(arr[p], arr[j]);
            p = j;
        }else
            break;
    }
}

template<class T>
void heapify(T arr[], int n){
    int k = n - 1;
    for (int i = (k-1)/2; i >= 0; i--)
        shiftdown<T>(arr, n, i);
}

template<class T>
void heapSort(T arr[], int n){
    heapify<T>(arr, n);
    for (int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        shiftdown<T>(arr, i, 0);
    }
}
#pragma endregion

int main(){

    //test sort
    int n = 10000;
    int* arr = SortTestHelper::generateRandomArray(n, 0, 10000);
    int* arr1 = SortTestHelper::copyArray<int>(arr, n);
    int* arr2 = SortTestHelper::copyArray<int>(arr, n);
    int* arr3 = SortTestHelper::copyArray<int>(arr, n);
    int* arr4 = SortTestHelper::copyArray<int>(arr, n);
    int* arr5 = SortTestHelper::copyArray<int>(arr, n);
    int* arr6 = SortTestHelper::copyArray<int>(arr, n);

    // int a1[10] = {3, 3, 5, 7, 1, 4, 3, 7, 4, 0};
    // arr6 = a1;
    
    // SortTestHelper::printArray(arr6, 10);


    // int a[] = {3, 1, 7, 5, 9};
    // arr = a;
    // quickSort<int>(arr, n);
    // SortTestHelper::printArray(arr, n);

    // mergeSorBtmup<int>(arr, n);
    // SortTestHelper::printArray(arr, n);

    // _insertionSort<int>(arr, 0, n);
    // SortTestHelper::printArray<int>(arr, n);
    // SortTestHelper::printArray<int>(arr1, n);

    // test heap
    // int a[10] = {0, 2, 6, 1, 0, 3, 8, 9, 5, 10};
    // arr5 = a;
    // Heap<int> heap(arr5, n);
    // cout << heap;
    // // cout << heap.size();
    // int size = heap.size();
    // for (int i = 0; i < size; i++){
    //     cout << heap.extractMax() << " ";

    // }
    // cout << endl;

    SortTestHelper::testSort("insertion sort", insertionSort<int>, arr, n);
    SortTestHelper::testSort("merge sort", mergeSort<int>, arr1, n);
    SortTestHelper::testSort("merge sort update", mergeSortUpdate<int>, arr2, n);
    SortTestHelper::testSort("merge sort bottom up", mergeSortBtmup<int>, arr3, n);
    SortTestHelper::testSort("quick sort", quickSort<int>, arr4, n);
    
    SortTestHelper::testSort("heap sort", heapSort<int>, arr6, n);




    return 0;
}
