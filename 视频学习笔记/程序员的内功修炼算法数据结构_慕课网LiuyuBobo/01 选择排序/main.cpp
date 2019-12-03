
#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"
#include "SelectionSort.h"
using namespace std;


int _main(void)
{
    int  n    = 10000;
    int* arr  = SortTestHelper::generateRandomArray(n,0,n);
    selectionSort(arr,n);
    SortTestHelper::printArray(arr,n);
    
    Student d[4] = {{"D",90},{"C",100},{"B",95},{"A",95}};
    selectionSort(d,4);
    SortTestHelper::printArray(d,4);
    
    delete[] arr;
    
    system("pause");
    
    return 0;
}


int main(void)
{
    int  n   = 0        ;
    int* arr = NULL     ;
    
    n = 1000;
    arr = SortTestHelper::generateRandomArray(n,0,n);
    SortTestHelper::testSort("selectionSort",selectionSort,arr,n);
    delete[] arr;
    
    
    n = 10000;
    arr = SortTestHelper::generateRandomArray(n,0,n);
    SortTestHelper::testSort("selectionSort",selectionSort,arr,n);
    delete[] arr;
    

    n = 100000;
    arr = SortTestHelper::generateRandomArray(n,0,n);
    SortTestHelper::testSort("selectionSort",selectionSort,arr,n);
    delete[] arr;

    
    
    //system("pause");
    return 0;
    
 
}