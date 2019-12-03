#ifndef __INDEXMAXHEAP_H__
#define __INDEXMAXHEAP_H__

#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
using namespace std; // swap


template <typename Item>
class IndexMaxHeap_Array
{
    private:
        Item*          data      ;   /* 堆元素存储位置首地址  */
        int*           indexes   ;   /* 索引数组              */
        int*           reverse   ;   /* 反向映射数据,reverse 表示索引i在indexes中的位置    */
        unsigned int   count     ;   /* 堆中已有元素个数      */
        unsigned int   capacity  ;   /* 堆容量                */

        void shift_up( int ind )
        {
            while(   (ind > 1)  /* 这里要先满足,不然下一个条件判断直接就会越界 */
                  && (data[indexes[ind / 2]] < data[indexes[ind]]) /*大根堆:父节点的值小于新加入的孩子节点,且 ind/2 至少为1 均满足时才交换*/
                 )
            {
                 swap(indexes[ind/2],indexes[ind]);   /* 交换索引               */
                 //reverse[indexes[ind/2]] = ind / 2;   /* 分別设置反向查找索引   */
                 //reverse[indexes[ind]]   = ind;
                 swap(reverse[indexes[ind/2]], reverse[indexes[ind]]);

                 ind /= 2;                      /* 待比较对象迁移到父节点*/
            };
        }

        /**/
        void shift_down( int ind )
        {
            int moreBiggerIndex = 0;
            while(2*ind <=count) /* 有左孩子就是有孩子*/
            {
                moreBiggerIndex = 2*ind;
                if(  (moreBiggerIndex+1<=count)
                   &&(data[indexes[moreBiggerIndex+1]]>data[indexes[moreBiggerIndex]])
                )
                {
                    moreBiggerIndex += 1; /* 更新到右孩子*/    
                }
                if(data[indexes[ind]]<data[indexes[moreBiggerIndex]])
                {
                    swap(indexes[ind],indexes[moreBiggerIndex]);
                    reverse[indexes[ind]] = ind;
                    reverse[indexes[moreBiggerIndex]] = moreBiggerIndex;
                    ind = moreBiggerIndex;
                }
                else
                {
                    break;
                }
            };

        }

    public:
        IndexMaxHeap_Array( unsigned int capacity )
        {
            this->data     = new Item[capacity+1]   ; /* 根节点从1开始编号*/
            this->indexes  = new int[capacity+1]    ;
            this->reverse  = new int[capacity+1]    ;
            this->count    = 0                      ;
            this->capacity = capacity               ;
            
            for(int i = 0 ; i < capacity+1;i++)
            {
                reverse[i] = 0; /*初始化标记0,0没有意义,表示不存在*/
            }
        }
        
        ~IndexMaxHeap_Array()
        {
            delete[] data;
            delete[] indexes;
            delete[] reverse;
        }
   
        /* 获取堆的元素个数 */
        int getSize(void)
        {
            return count;
        }
        
        /* 堆是否为空 */
        bool isEmpty()
        {
            return(count==0);
        }
        /* 向大根堆添加元素 */
        void insert(Item item , unsigned int ind)    /* ind 在外部表示数组的索引, 在内部表示数组的索引加1*/
        {
            if(count>=capacity)
            {
                cout << "堆已经满了" << endl;
                return ;
                /* 或者追加空间*/
            }
            ind = ind + 1;
            assert( ind >=1 && ind <= capacity);
            assert( count+1 <= capacity);
            data[ind] = item;
            indexes[count+1] = ind;
            reverse[ind] = count + 1;
            count++;
            shift_up(count);    /* 调整以维持堆的定义*/
        }
        
        /* 取出当前最大根对应的索引 */
        int getMax() 
        {
            Item item;
            if(count < 1)
            {
                cout << "此二叉堆已经为空,无法进行取出操作" << endl;
                return 0;
            }
            
            /* 获得根节点 */
            int ret = indexes[1] - 1; /* 获取节点*/
            item = data[indexes[1]];
            swap(indexes[1],indexes[count]); /*把最后一个和第一个进行交换*/
            reverse[indexes[1]] = 1;
            reverse[indexes[count]] = 0;
            count--;                    /* 进行计数调整*/
            shift_down(1);
            return ret;
        }
        
        bool contain(int ind)
        {
            assert(ind+1 >=1 && ind+1 <= capacity);
            return (reverse[ind+1] != 0) ;
        }
        
        /* 通过索引获得数据*/
        Item getItem( int ind)
        {
            assert(contain(ind));
            return data[ind+1];
        }
        
        /* 改变堆中元素的值*/
        void changeElement(Item newItem,int ind) // O(n)复杂度
        {
            assert(contain(ind));
            ind += 1;
            data[ind] = newItem; 
            //找到indexes[j] = ind ,j表示data[i]在堆中的位置
            //for(int j = 1 ; j <= count ; j++)
            //{
            //    if(indexes[j] == ind)
            //    {
            //        shift_up(j);
            //        shift_down(j); 
            //    }                    
            //}
            int j = reverse[ind];
            shift_down(j);
            shift_up(j); 
        }
};

#endif /* !__INDEXMAXHEAP_H__ */