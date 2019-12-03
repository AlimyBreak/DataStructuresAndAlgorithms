
#ifndef __SORTTESTHELPER_H__
#define __SORTTESTHELPER_H__

#include <iostream>
#include <ctime>    // time(NULL) clock
#include <cassert>  // assert()
using namespace std;

// 用来存放测试相关的命名
namespace SortTestHelper{
    
    /* 生成有n个元素的随机数组,每个元素的随机范围为[rangeL,rangeR]*/
    int* generateRandomArray( int n         ,
                              int rangeL    ,
                              int rangeR
                            )
    {
        
        assert( rangeL <= rangeR);
        int* arr = new int[n];
        srand(time(NULL));
        for(int i = 0 ; i < n ; i++)
        {
            arr[i] = rand()% ( rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }     
    
    /* 生成近乎有序的数组 */
    int* generateNearlyOrderedArray( int n , int swaptimes) 
    {
        /* 1.生成完全有序的数组   */
        /* 2.随机挑选几对进行交换 */
        int* arr = new int[n];
        
        for(int i = 0 ; i < n ; i++)
        {
            arr[i] = i;
        }
        
        srand(time(NULL));
        for(int i = 0 ; i < swaptimes ; i++)
        {
            int j = rand() % n;
            int k = rand() % n;
            swap(arr[j],arr[k]);
        }
        
        return arr;
        
    }
    
    
    template <typename T>
    bool isSorted(T arr[],int n )
    {
        bool ret_val = true;
        do{
            for(int i = 0 ; i < n - 1 ;i++)
            {
                if(arr[i] > arr[i+1])
                {
                    ret_val = false;
                    break;
                }
            }
            
        }while(0);
        return ret_val;
    }
    
    
    // 模板函数必须写在.h文件中?
    // 如果函数模板按照普通的函数声明放在头文件的，定义放在.cpp文件,会出现错误.
    // https://blog.csdn.net/legendavid/article/details/70160319
    template <typename T>
    void printArray(T arr[],int n )
    {
        for(int i = 0 ; i < n ; i ++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    template <typename T>
    void testSort( string           sortMethod      ,
                   void(*sortFunc)(T[],int)         ,
                   T                arr[]           ,
                   int              n
                 )
    {
        clock_t startTime = clock();
        sortFunc(arr,n);
        clock_t endTime = clock();
        assert(isSorted(arr,n)); //检查算法


        cout << sortMethod 
             << " : " 
             << (double)(endTime - startTime ) / CLOCKS_PER_SEC
             << " s" 
             << endl;
             
        return ;
    }
    

    int* copyIntArray(int arr_src[],int n)
    {
        int* arr_dst = new int[n];
        copy(arr_src,arr_src+n,arr_dst);
        return arr_dst;
    }
    
    

}


#endif // __SORTTESTHELPER_H__


