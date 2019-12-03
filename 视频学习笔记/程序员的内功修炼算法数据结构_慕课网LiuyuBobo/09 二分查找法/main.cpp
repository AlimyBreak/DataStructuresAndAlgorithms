
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "binarySearch.h"

using namespace std;

/* 测试集中排序算法的性能*/

int main(void)
{
    int arr[10] = { 0,};
    for(int i = 0 ; i < 10 ; i ++)
    {
        arr[i] = i ;
    }
    
    int ind  = binarySearch(arr,10,5);
    
    if(ind == -1)
    {
        cout << "Search failed!" << endl;
    }
    else
    {
        cout << "Search sucessfully ! index = " << ind <<"!" << endl;
    }

}
