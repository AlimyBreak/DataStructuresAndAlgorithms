
#ifndef __INSERTIONSORT_H__
#define __INSERTIONSORT_H__

//#include "InsertionSort.h"



template <typename T >
void insertionSort( T arr[] ,int n )
{
    for( int i = 1 ; i < n ; i++)
    {
        for(int j = i;j>0;j--)
        {
            if(arr[j] < arr[j-1])
            {
                swap(arr[j],arr[j-1]);
            }
            else
            {
                break; /* 以前排序好,可以提前结束*/
            }
        }
    }
}


template <typename T >
void insertionSort_opt( T arr[] , int n )
{
    T temp ;
    int j = 0;
    for( int i = 1; i < n ; i ++)
    {
        temp = arr[i];
        // 计算出 temp 应该插入的位置
        for(j = i ; j > 0 ; j--)
        {
            if( temp < arr[j-1])
            {
                arr[j] = arr[j-1];
            }
            else
            {
                break;
            }
            
            
        }
        arr[j] = temp;
    }
    
}




#endif /* !__INSERTIONSORT_H__ */ 