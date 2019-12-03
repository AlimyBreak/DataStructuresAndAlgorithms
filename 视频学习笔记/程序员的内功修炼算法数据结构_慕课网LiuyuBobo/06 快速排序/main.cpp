
#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
using namespace std;

int main(void)
{
    int  n    = 0        ;
    int* arr1 = NULL     ;
    int* arr2 = NULL     ;
    int* arr3 = NULL     ;
    int* arr4 = NULL     ;
    int* arr5 = NULL     ;
    
    n    = 100*10000;
    arr1 = SortTestHelper::generateRandomArray(n,0,n);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    SortTestHelper::testSort("mergeSort_Bottom2Top",mergeSort_Bottom2Top,arr1,n);
    SortTestHelper::testSort("mergeSort",mergeSort,arr2,n);
    SortTestHelper::testSort("quickSort",quickSort,arr3,n);
    
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    

    n    = 10000*100;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,10);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    SortTestHelper::testSort("mergeSort_Bottom2Top",mergeSort_Bottom2Top,arr1,n);
    SortTestHelper::testSort("mergeSort",mergeSort,arr2,n);
    SortTestHelper::testSort("quickSort",quickSort,arr3,n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    
    
    
    
    n    = 100000;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    arr4 = SortTestHelper::copyIntArray(arr1,n);
    arr5 = SortTestHelper::copyIntArray(arr1,n);
    SortTestHelper::testSort("mergeSort_Bottom2Top",mergeSort_Bottom2Top,arr1,n);
    SortTestHelper::testSort("mergeSort",mergeSort,arr2,n);
    SortTestHelper::testSort("quickSort",quickSort,arr3,n);
    SortTestHelper::testSort("quickSort2",quickSort2,arr4,n);
    SortTestHelper::testSort("quickSort3",quickSort3ways,arr5,n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
   
    
    return 0;
}