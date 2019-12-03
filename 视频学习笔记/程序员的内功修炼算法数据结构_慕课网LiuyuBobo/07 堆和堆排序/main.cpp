
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "SortTestHelper.h"
#include "MaxHeap.h"
#include "HeapSort1.h"
#include "HeapSort2.h"
#include "HeapSort3.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"

using namespace std;

/* 测试大根堆的插入和取出功能*/
int _main(void)
{
    MaxHeap_Array<int> maxheap = MaxHeap_Array<int>(100);
    cout << maxheap.getSize() << endl;
    
    srand(time(NULL));
    for(int i = 0 ; i < 15 ; i++)
    {
        maxheap.insert(rand()%100);
    }

    while(!maxheap.isEmpty())
    {
        cout << maxheap.getMax() << endl;  
    }
    maxheap.testPrint();
    return 0;
}

/* 测试集中排序算法的性能*/

int main(void)
{
    int n = 5*100*100;

    cout << " Random Array: size = " << n << ",range [ 0 ~" << n <<"]" << endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1,n);
    int* arr3 = SortTestHelper::copyIntArray(arr1,n);
    int* arr4 = SortTestHelper::copyIntArray(arr1,n);
    int* arr5 = SortTestHelper::copyIntArray(arr1,n);
    int* arr6 = SortTestHelper::copyIntArray(arr1,n);
    int* arr7 = SortTestHelper::copyIntArray(arr1,n);
    int* arr8 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort( "SelectionSort", selectionSort ,arr1 ,n);
    SortTestHelper::testSort( "BubbleSort"   , bubbleSort    ,arr2 ,n);
    SortTestHelper::testSort( "insertionSort", insertionSort ,arr3 ,n);
    SortTestHelper::testSort( "mergeSort"    , mergeSort     ,arr4 ,n);
    SortTestHelper::testSort( "heapSort1"    , heapSort1     ,arr5 ,n);
    SortTestHelper::testSort( "heapSort2"    , heapSort2     ,arr6 ,n);
    SortTestHelper::testSort( "heapSort3"    , heapSort3     ,arr7 ,n);
    SortTestHelper::testSort( "quickSort3ways"    , quickSort3ways     ,arr8 ,n);


    
    delete[] arr1;
    delete[] arr2;    
    delete[] arr3;    
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;

    cout << " Random Array: size = " << n << ",NearlyOrdered [ 0 ~ "<< n << "]," <<  "swap_times :"<< 30 <<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,30);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    arr4 = SortTestHelper::copyIntArray(arr1,n);
    arr5 = SortTestHelper::copyIntArray(arr1,n);    
    arr6 = SortTestHelper::copyIntArray(arr1,n);    
    arr7 = SortTestHelper::copyIntArray(arr1,n);  
    arr8 = SortTestHelper::copyIntArray(arr1,n);      
    SortTestHelper::testSort( "SelectionSort", selectionSort ,arr1 ,n);
    SortTestHelper::testSort( "BubbleSort"   , bubbleSort    ,arr2 ,n);
    SortTestHelper::testSort( "insertionSort", insertionSort ,arr3 ,n);
    SortTestHelper::testSort( "mergeSort"    , mergeSort     ,arr4 ,n);
    SortTestHelper::testSort( "heapSort1"    , heapSort1     ,arr5 ,n);
    SortTestHelper::testSort( "heapSort2"    , heapSort2     ,arr6 ,n);
    SortTestHelper::testSort( "heapSort3"    , heapSort3     ,arr7 ,n);
    SortTestHelper::testSort( "quickSort3ways"    , quickSort3ways     ,arr8 ,n);
    delete[] arr1;
    delete[] arr2;    
    delete[] arr3;    
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;

    cout << " Random Array: size = " << n << ",range [ 0 ~" << 10 <<"]" << endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    arr4 = SortTestHelper::copyIntArray(arr1,n);
    arr5 = SortTestHelper::copyIntArray(arr1,n);
    arr6 = SortTestHelper::copyIntArray(arr1,n);
    arr7 = SortTestHelper::copyIntArray(arr1,n);
    arr8 = SortTestHelper::copyIntArray(arr1,n);
    SortTestHelper::testSort( "SelectionSort", selectionSort ,arr1 ,n);
    SortTestHelper::testSort( "BubbleSort"   , bubbleSort    ,arr2 ,n);
    SortTestHelper::testSort( "insertionSort", insertionSort ,arr3 ,n);
    SortTestHelper::testSort( "mergeSort"    , mergeSort     ,arr4 ,n);
    SortTestHelper::testSort( "heapSort1"    , heapSort1     ,arr5 ,n);
    SortTestHelper::testSort( "heapSort2"    , heapSort2     ,arr6 ,n);
    SortTestHelper::testSort( "heapSort3"    , heapSort3     ,arr7 ,n);
    SortTestHelper::testSort( "quickSort3ways"    , quickSort3ways     ,arr8 ,n);
    delete[] arr1;
    delete[] arr2;    
    delete[] arr3;    
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;


    


    return 0;
}
