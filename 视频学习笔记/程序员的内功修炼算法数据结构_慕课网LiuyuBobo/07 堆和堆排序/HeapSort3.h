#ifndef __HEAPSORT3_H__
#define __HEAPSORT3_H__


template <typename T>
void __shiftDown( T arr[] , int size , int i )
{
    int moreBiggerIndex = 0;
    while(2*i+1 <size) // 有左孩子即可
    {
        moreBiggerIndex = 2*i + 1;
        if(  ( moreBiggerIndex + 1 < size                    )
           &&( arr[moreBiggerIndex+1] > arr[moreBiggerIndex] )
        )
        {
            moreBiggerIndex += 1;
        }
        
        if(arr[moreBiggerIndex] > arr[i])
        {
            swap(arr[moreBiggerIndex] , arr[i]);
            i = moreBiggerIndex;
        }
        else
        {
            break;  /* 已经满足二叉堆性质, 直接*/
        }
        
    }
}


template <typename T>
// 原地堆排序
void heapSort3(T arr[],int n)
{   

    // 1.heapify
    for( int i = (n-1) / 2 ; i >= 0 ; i--)
    {
        __shiftDown(arr,n,i);
    }
    
    // 2.swap & __shiftDown
    for( int i = n-1 ; i > 0 ; i--)
    {
        swap(arr[0],arr[i]);
        __shiftDown(arr,i,0); // i 就是当前数据长度
    }
    
}
#endif