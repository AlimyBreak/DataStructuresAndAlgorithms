
#ifndef __MERGESORT_H__
#define __MERGESORT_H__

/* #include "MergeSort.h" */


template <typename T>
/*
    归并过程,对arr[left,right]的范围进行归并
*/
void __merge( T arr[], int left, int mid,int right)
{
    int i = 0;
    int j = 0;
    int k = 0;
    T* aux = new T[right-left+1];
    
    /* 先拷贝出来 */
    for(i = left ; i<=right;i++)
    {
        aux[i-left] = arr[i];
    }
    
    /* 进行有序数组合成 */
    i = left;
    j = mid + 1;
    for(k=left;k<=right;k++)    /* 要存入位置的索引*/
    {
        if(i>mid)   /* 索引合法性*/
        {
            arr[k] = aux[j-left];
            j++;
        }
        else if(j > right) /* 索引合法性*/
        {
            arr[k] = aux[i-left];
            i++;
        }
        else if( aux[i-left] < aux[j-left]) /* 索引已经合法 */
        {
            arr[k] = aux[i-left];
            i++;
        }
        else
        {
            arr[k] = aux[j-left];
            j++;
        }
    }
    
    delete[] aux;
    return ;
}

template <typename T>
/*
    递归使用归并排序,对arr[left,right]的范围进行排序
*/
void __mergeSort( T arr[], int left,int right) // 表征私有,不应该被外部调用,但可以被外部调用
{
    /* 递归到顶*/
    //if(left>=right)
    //{
    //    return ;
    //}
    if(right-left <= 15)
    {
        insertionSort_opt(&arr[left],right-left+1);
        return ;
    }
    int mid = left + (right - left)/2;  // 防止溢出  
    __mergeSort(arr,left,mid);
    __mergeSort(arr,mid+1,right);
    
    /* 优化添加,针对已经有序的不需要重新归并排序*/
    if(arr[mid]<=arr[mid+1])
    {
        return ;
    }
    else
    {
        __merge(arr,left,mid,right); /* 两个有序数组归并过程*/
    }
}

template <typename T>
void mergeSort( T arr[] , int n )
{
    __mergeSort(arr,0,n-1);
}

/* 自底而下的进行归并排序 */
template <typename T>
void mergeSort_Bottom2Top(T arr[] , int n )
{    
    for( int size = 1;size <= n ; size*=2 ) /* 归并长度 1,2,4,8...依次递增 */
    {
        for( int i = 0 ; i+size < n; i += 2*size) /* 一次归并消耗2*size个元素 */
        {
            /* 两个才能进行归并 */
            int left  = i; 
            int mid   = i + size - 1;
            int right = i + size*2-1 > n-1? n-1:i+size*2-1; /* 防止越界 */
            /* 将arr[i...i+size-1] 和 arr[i+size...i+2*size-1] 进行归并 */
            /* i+size < n 的循环进入条件使得arr[mid+1]一定存在 */
            if(arr[mid]>arr[mid+1] )/* 被添加的优化代码,可以不进入归并过程,算法允许偷懒啦*/
            {
                if(size>8)
                {
                    __merge(arr,left,mid,right);
                }
                else
                {
                    insertionSort_opt(&arr[left],right-left+1); /* 被添加的优化代码,小数组直接用插入排序 */
                }
            }
        }
    }
}

#endif /* !__MERGESORT_H__ */

