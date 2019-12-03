


#ifndef __BINARYSEARCH_H__
#define __BINARYSEARCH_H__


template <typename T>
/* 二分查找法,在有序数组arr中,查找target并返回其索引
若查找失败,返回-1
arr 升序
*/
int binarySearch(T arr[] , int n , T target)
{
    /* 查找只在 [left,right] 中进行 */
    int left    = 0;
    int right   = 0;
    int mid     = 0;
    int ret_val = 0;
    
    left    = 0     ;
    right   = n -1  ;
    ret_val = -1    ;
    
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        if(arr[mid] == target)
        {
            ret_val = mid;
            break;
        }
        else if(arr[mid] > target)
        {
            
            right = mid - 1; /* mid 已经比较过,下次不需要mid了*/
        }
        else
        {
            left = mid + 1;
        }
    };
    
    return ret_val;
}




#endif