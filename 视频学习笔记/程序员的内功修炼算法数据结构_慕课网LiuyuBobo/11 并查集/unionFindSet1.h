

#ifndef __UNIONFINDSET1_H__
#define __UNIONFINDSET1_H__
#include <cassert>
#include <iostream>

using namespace std;

namespace UF1{
    
    class UnionFindSet
    {
        private:
            int*     id     ;
            int      count  ;
        
        
        public:
            UnionFindSet(int n )
            {
                /* n 表示这个并查集有几何元素 */
                this->id    = new int[n]    ;
                this->count = n             ;
                for(int i = 0 ; i < n ; i++)
                {
                    id[i] = i; /* 初始化时,每个元素都独立成组    */
                }
            }
            
            
            /*
             quick find
            */
            int find(int p )
            {
                assert( p >= 0 && p < count);
                return id[p];
            }
            
            /*
              Quick Find 的union的时间复杂度为O(n) 
              合并p,q所在的两个组,将p所在的组合并到q组中去
            */
            void unionElement(int p , int q)
            {
                int pID = find(p);
                int qID = find(q);
                
                if(pID != qID)
                {
                    
                    for(int i = 0 ; i < count ; i++)
                    {
                        if(id[i] == pID)
                        {
                            id[i]  = qID;
                        }
                    }
                }
                else
                {
                    return ;
                }
       
            }
            
            
            
            bool isConnected(int p , int q)
            {
                return find(p) == find(q);
            }
            
            
            
            
            ~UnionFindSet()
            {
                delete[] this->id;
                count = 0;
            }
        
        
    };
}




#endif /* !__UNIONFINDSET_H__ */