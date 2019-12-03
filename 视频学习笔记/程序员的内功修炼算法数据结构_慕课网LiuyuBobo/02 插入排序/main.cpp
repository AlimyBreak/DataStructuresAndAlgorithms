
#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
using namespace std;


int main(void)
{
    int  n    = 0        ;
    int* arr1 = NULL     ;
    int* arr2 = NULL     ;
    int* arr3 = NULL     ;
    
    n    = 10000*5;
    arr1 = SortTestHelper::generateRandomArray(n,0,n);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    SortTestHelper::testSort("selectionSort",selectionSort,arr1,n);
    SortTestHelper::testSort("insertionSort",insertionSort,arr2,n);
    SortTestHelper::testSort("insertionSort_opt",insertionSort_opt,arr3,n);
    
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
        
    n    = 10000*5;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,100);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    
    SortTestHelper::testSort("selectionSort",selectionSort,arr1,n);
    SortTestHelper::testSort("insertionSort",insertionSort,arr2,n);
    SortTestHelper::testSort("insertionSort_opt",insertionSort_opt,arr3,n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    




    
    
    //system("pause");
    return 0;
    
 
}