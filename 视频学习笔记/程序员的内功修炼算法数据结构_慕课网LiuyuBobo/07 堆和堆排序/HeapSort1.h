

#ifndef __HEAPSORT1_H__
#define __HEAPSORT1_H__
#include "MaxHeap.h"
template <typename T>
void heapSort1(T arr[],int n)
{
    MaxHeap_Array<T> maxHeap = MaxHeap_Array<T>(n);
    for(int i = 0 ; i < n ; i++)
    {
        maxHeap.insert(arr[i]);
    }

    for(int i = n-1 ; i>=0 ; i--)
    {
        arr[i] = maxHeap.getMax();
    }
}







#endif
