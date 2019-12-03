
#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
using namespace std;

int main(void)
{
    int  n    = 0        ;
    int* arr1 = NULL     ;
    int* arr2 = NULL     ;
    int* arr3 = NULL     ;
    int* arr4 = NULL     ;
    
    n    = 5*10000;
    arr1 = SortTestHelper::generateRandomArray(n,0,n);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    SortTestHelper::testSort("insertionSort",insertionSort,arr1,n);
    SortTestHelper::testSort("bubbleSort",bubbleSort,arr2,n);
    SortTestHelper::testSort("mergeSort",mergeSort,arr3,n);
    
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    
    
    n    = 5*10000;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,100);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    arr4 = SortTestHelper::copyIntArray(arr1,n);
    SortTestHelper::testSort("insertionSort",insertionSort,arr1,n);
    SortTestHelper::testSort("bubbleSort",bubbleSort,arr2,n);
    SortTestHelper::testSort("mergeSort",mergeSort,arr3,n);
    SortTestHelper::testSort("mergeSort_Bottom2Top",mergeSort_Bottom2Top,arr4,n);

    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    
    
    return 0;
}