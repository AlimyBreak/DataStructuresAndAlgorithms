
#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

//#include "QuickSoty.h"


template <typename T >
void ____swap(T& a, T& b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

template <typename T>
/* 对arr[left...right]进行一次Partition操作
    返回值是一个索引,操作结果:
    arr[left...p-1] < arr[p]
    arr[p..left] >= arr[p]
*/
int __partition( T arr[] , int left , int right)
{
    
    
    T   v    = arr[left]    ;
    int p    = left         ;
    
    
    /* 优化代码,随机的选一个作为v*/
    ____swap(arr[left],arr[rand()%(right-left+1) + left]);
    v = arr[left];
    
    /* arr[left+1...p] < v , arr[p+1...i] >= v*/
    for(int i = left+1 ; i <= right ; i++)
    {
        if(arr[i] >= v)
        {
            continue;
        }
        else
        {
            ____swap(arr[p+1],arr[i]);
            p++;
        }
    }
    /* 把v交换到它应该在的地方*/
    ____swap(arr[left],arr[p]);
    return p;
}

template <typename T >
/* 将arr[left...right]进行快速排序 */
void __quickSort( T arr[] , int left , int right)
{
    

    if(left >= right)
    {
        return ;
    }
    if(right-left <=15) /* 添加的优化代码*/
    {
        insertionSort_opt(&arr[left],right-left+1);
        return ;
    }
    /* 1.进行Partition*/
    int p = __partition(arr,left,right); /*返回索引值 */
    /* 2.后面两部分分别进行快速排序*/
    __quickSort(arr,left,p-1);  /* 前后分别进行快速排序*/
    __quickSort(arr,p+1,right);
}


template <typename T >
void quickSort( T arr[] ,int n )
{
    srand(time(NULL));
    __quickSort(arr,0,n-1);
}



 /*返回索引值 */
template <typename T >
int __partition2(T arr[] , int left , int right)
{
    T   v;
    int i = 0;
    int j = 0;
    
    /* 优化代码,随机的选一个作为v*/
    ____swap(arr[left],arr[rand()%(right-left+1) + left]);
    v = arr[left];
    i = left+1;     /* arr[left+1...i) <= v ,arr(j...r] >= v*/
    j = right;
    
    while(1)
    {
        while(arr[i]<v && i <= right )
        {
            i++; //遇到大于v的就停止,找到不满足的
        }
        while(arr[j]>v && j >= left+1)
        {
            j--;
        }
        
        if(i>j)
        {
             break;
        }
        ____swap(arr[i],arr[j]);
        i++;    /* 进入下一轮判断*/
        j--;
    };
    
    ____swap(arr[left],arr[j]);
    return j;
}


template <typename T >
void __quickSort2( T arr[] , int left , int right)
{
    if(left >= right)
    {
        return ;
    }
    if(right-left <=15) /* 添加的优化代码*/
    {
        insertionSort_opt(&arr[left],right-left+1);
        return ;
    }
    
    /* 1.进行Partition*/
    int p = __partition2(arr,left,right); /*返回索引值 */
    /* 2.后面两部分分别进行快速排序*/
    __quickSort2(arr,left,p-1);  /* 前后分别进行快速排序*/
    __quickSort2(arr,p+1,right);
    
    
}

template <typename T >
void quickSort2( T arr[], int n )
{
    srand(time(NULL));
    __quickSort2(arr,0,n-1);
    return ;
}





template <typename T >
void __quickSort3( T arr[] , int left , int right)
{
    if(left >= right)
    {
        return ;
    }
    if(right-left <=15) /* 添加的优化代码*/
    {
        insertionSort_opt(&arr[left],right-left+1);
        return ;
    }
    
    /* 1.进行Partition*/
    ____swap(arr[left],arr[rand()%(right-left+1)+left]);
    T v = arr[left];
    
    int lt = left    ;    // arr[left+1...lt]<v
    int gt = right+1 ;    // arr[gt...t]>v
    int i  = left +1 ;    // arr[lt+1...i) == v
    
    while( i<gt)
    {
        if(arr[i] < v)
        {
            ____swap(arr[i],arr[lt+1]);
            lt++;
            i++;
        }
        else if(arr[i]>v)
        {
            swap(arr[i],arr[gt-1]);
            gt--;
            //i++; arr[i] 是被新交换而来的,需要重新判断
        }
        else //arr[i]==v
        {
            i++;
        }
    };
    ____swap(arr[left],arr[lt]);
    
    /* 2.后面两部分分别进行快速排序*/
    __quickSort3(arr,left,lt-1);  /* 前后分别进行快速排序*/
    __quickSort3(arr,gt,right);
}


template <typename T >
void quickSort3ways( T arr[], int n )
{
    srand(time(NULL));
    __quickSort3(arr,0,n-1);
    return ;
}






#endif /* !__QUICKSORT_H__ */ 


