#ifndef __HEAPSORT2_H__
#define __HEAPSORT2_H__
#include "MaxHeap.h"
template <typename T>
void heapSort2(T arr[],int n)
{
    MaxHeap_Array<T> maxHeap = MaxHeap_Array<T>(arr,n);
    for(int i = n-1 ; i>=0 ; i--)
    {
        arr[i] = maxHeap.getMax();
    }
}
#endif