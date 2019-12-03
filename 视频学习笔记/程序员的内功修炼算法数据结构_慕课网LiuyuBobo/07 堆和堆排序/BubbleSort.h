
#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

//#include "BubbleSort.h"



template <typename T >
void bubbleSort( T arr[] ,int n )
{
    for(int i = 1 ; i < n;i++)  // (i=1,2,...,n-1)
    {
        for(int j = 0;j < n-i;j++)  // j=0,1,2,3,...,n-i-1
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


#if 0 // todo
template <typename T >
void bubbleSort_opt( T arr[] , int n )
{
    T temp ;
    int j = 0;
    for( int i = 1; i < n ; i ++)
    {
        for(j = 0 ; j < n - i ; j++)
        {

                    
        }
        arr[j] = temp;
    }
}
#endif




#endif /* !__BUBBLESORT_H__ */ 


