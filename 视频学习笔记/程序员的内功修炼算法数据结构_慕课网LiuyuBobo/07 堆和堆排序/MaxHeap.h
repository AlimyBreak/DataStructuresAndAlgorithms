
#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__
#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
using namespace std; // swap


template <typename Item>
class MaxHeap_Array
{
    private:
        Item*          data      ;   /* 堆元素存储位置首地址   */
        int            count     ;   /* 堆中已有元素个数       */
        unsigned int   capacity  ;   /* 堆容量                */

        void shift_up( int ind )
        {
            while(  (data[ind/2] < data[ind])   /*大根堆:父节点的值小于新加入的孩子节点,且 ind/2 至少为1 均满足时才交换*/
                  &&(ind > 1)
                 )
            {
                 swap(data[ind/2],data[ind]);   /* 交换 */
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
                   &&(data[moreBiggerIndex+1]>data[moreBiggerIndex])
                )
                {
                    moreBiggerIndex += 1; /* 更新到右孩子*/    
                }
                if(data[ind]<data[moreBiggerIndex])
                {
                    swap(data[ind],data[moreBiggerIndex]);
                    ind = moreBiggerIndex;
                }
                else
                {
                    break;
                }
            };

        }




    public:
        MaxHeap_Array( unsigned int capacity )
        {
            this->data     = new Item[capacity+1]   ; /* 根节点从1开始编号*/
            this->count    = 0                      ;
            this->capacity = capacity               ;
        }
        template<typename T>
        MaxHeap_Array( T arr[],int n )
        {
            this->data = new Item[n+1];
            this->count = n;
            this->capacity = n;
            for(int i = 0 ; i < n ;i++)
            {
                data[i+1] = arr[i];
            }
            /* Heapify过程*/
            for(int i = count/2;i>=1;i--)
            {
                shift_down(i);
            }
        }
        ~MaxHeap_Array()
        {
            delete[] data;
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
        void insert(Item item)
        {
            if(count>=capacity)
            {
                cout << "堆已经满了" << endl;
                return ;
                /* 或者追加空间*/
            }
            data[count+1] = item;
            count++;
            shift_up(count);    /* 调整以维持堆的定义*/
        }

        /* 取出当前最大根 */
        Item getMax() 
        {
            Item item;
            if(count < 1)
            {
                cout << "此二叉堆已经为空,无法进行取出操作" << endl;
                return item;
            }

            /* 获得根节点 */
            item = data[1];
            swap(data[1],data[count]); /*把最后一个和第一个进行交换*/
            count--;                    /* 进行计数调整*/
            shift_down(1);              /*把交换上来的数进行shift_down操作,以使堆继续满足大根堆的性质*/
            return item;
        }
        





        // 以树状打印整个堆结构
        // https://github.com/liuyubobobo/Play-with-Algorithms/blob/master/04-Heap/Course%20Code%20(C%2B%2B)/03-Shift-Up/main.cpp
        void testPrint()
        {
            // 我们的testPrint只能打印100个元素以内的堆的树状信息
            if( getSize() >= 100 )
            {
                cout<<"This print function can only work for less than 100 int";
                return;
            }
            // 我们的testPrint只能处理整数信息
            if( typeid(Item) != typeid(int) ){
                cout <<"This print function can only work for int item";
                return;
            }

            cout<<"The max heap size is: "<<getSize()<<endl;
            cout<<"Data in the max heap: ";
            for( int i = 1 ; i <= getSize() ; i ++ )
            {
                // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
                assert( data[i] >= 0 && data[i] < 100 );
                cout<<data[i]<<" ";
            }
            cout<<endl;
            cout<<endl;

            int n = getSize();
            int max_level = 0;
            int number_per_level = 1;
            while( n > 0 ) 
            {
                max_level += 1;
                n -= number_per_level;
                number_per_level *= 2;
            }

            int max_level_number = int(pow(2, max_level-1));
            int cur_tree_max_level_number = max_level_number;
            int index = 1;
            for( int level = 0 ; level < max_level ; level ++ )
            {
                string line1 = string(max_level_number*3-1, ' ');

                int cur_level_number = min(count-int(pow(2,level))+1,int(pow(2,level)));
                bool isLeft = true;
                for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ )
                {
                    putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                    isLeft = !isLeft;
                }
                cout<<line1<<endl;

                if( level == max_level - 1 )
                    break;

                string line2 = string(max_level_number*3-1, ' ');
                for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                    putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
                cout<<line2<<endl;

                cur_tree_max_level_number /= 2;
            }
    }
    
    
    void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft)
    {
        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) 
        {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else
        {
            if( isLeft)
            {
                line[offset + 0] = '0' + num;
            }
            else
            {
                line[offset + 1] = '0' + num;
            }
        }
    }

    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width)
    {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
    
    
        
};




 
#endif /* !__MAXHEAP_H__ */

