#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

//rand, srand, --> stdlib.h

namespace SortTestHelper{
    int* generateRandomArray(int n, int rangeL, int rangeR){
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    template<class T>
    void printArray(T arr[], int n){
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    template<class T>
    T* copyArray(T arr[], int n){
        T* arrDst = new T[n];
        for (int i = 0; i < n; i++)
            arrDst[i] = arr[i];
        return arrDst;
    }

    template<class T>
    bool isSorted(T arr[], int n){
        for (int i = 1; i < n; i++)
            if (arr[i] < arr[i-1])
                return false;
        cout << "sorted" << endl;
    }

    template<class T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n){
        clock_t startTime = clock();
        sort(arr, n);
        assert(isSorted<T>(arr, n));
        clock_t endTime = clock();
        cout << "total time for " << sortName << " is " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl; 
    }
}