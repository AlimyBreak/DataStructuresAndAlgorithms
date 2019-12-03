
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "IndexMaxHeap.h"

using namespace std;

/* 测试集中排序算法的性能*/

int main(void)
{


    int arr[5] = {1,2,3,2,1}; 
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        arr[i] = rand() % 5;
    }


    IndexMaxHeap_Array<int> indexmaxheap = IndexMaxHeap_Array<int>(5);
    
    for(int i = 0 ; i < 5 ; i ++)
    {
        indexmaxheap.insert(arr[i],i);
    }
    
    cout << "Items:" << endl;
    for(int i = 0 ; i < 5 ; i ++ )
    {
        cout << indexmaxheap.getItem(i) <<endl;
    }
    
    indexmaxheap.changeElement(8,1);
    arr[1] = 8;
    indexmaxheap.changeElement(7,3);
    arr[3] = 7;
    
    cout << "Items:" << endl;
    for(int i = 0 ; i < 5 ; i ++ )
    {
        cout << indexmaxheap.getItem(i) <<endl;
    }
    
    cout << "Sort result:" << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        cout << arr[indexmaxheap.getMax()] << endl;
    }

    //system("pause");
    return 0;
}
