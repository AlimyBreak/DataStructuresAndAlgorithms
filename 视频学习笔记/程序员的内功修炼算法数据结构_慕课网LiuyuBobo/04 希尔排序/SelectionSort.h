
#ifndef __SELECTIONSORT_H__
#define __SELECTIONSORT_H__

//#include "SelectionSort.h"


template <typename T >
void _swap(T& a, T& b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

template <typename T >
void selectionSort( T arr[] ,int n )
{
    
    int minIndex = 0;
    for( int i = 0 ; i < n ; i++)
    {
        // 寻找 [i,n)区间内的最小值
        minIndex = i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j] < arr[minIndex]) // 升序,小的往前排
            {
                minIndex = j;
            }
            // C++ 内置, 视C++标准支持情况,std 中就有或者 #include <algorithm>
            
        }
        _swap(arr[i],arr[minIndex]);
    }
}

#endif /* !__SELECTIONSORT_H__ */ 