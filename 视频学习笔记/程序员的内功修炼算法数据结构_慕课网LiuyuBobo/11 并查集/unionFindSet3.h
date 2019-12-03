

#ifndef __UNIONFINDSET3_H__
#define __UNIONFINDSET3_H__
#include <cassert>
#include <iostream>

using namespace std;

namespace UF3{
    
    class UnionFindSet
    {
        private:
            int*     parent     ;
            int*     sz         ; /*以i为根的集合中元素的个数*/
            int      count  ;
        
        
        public:
            UnionFindSet(int n )
            {
                /* n 表示这个并查集有几何元素 */
                this->parent = new int[n]    ;
                this->sz     = new int[n]    ;
                this->count  = n             ;
                for(int i = 0 ; i < n ; i++)
                {
                    parent[i] = i; /* 初始化时,每个元素都指向自己,每个都是父节点*/
                    sz[i]     = 1; /* 初始化时都指向自己,节点数都只有一个*/ 
                }
            }
            
            /* */
            int findRoot(int p)
            {
                assert( p>= 0 && p < count);
                while(p!=parent[p])
                {
                    p = parent[p];
                }
                return p;
            }
            /*
                quick union
            */
            void unionElement(int p , int q)
            {
                int pRoot = findRoot(p);
                int qRoot = findRoot(q);
                
                if(pRoot != qRoot)
                {
                    /* 尽量压低树的高度*/
                    if(sz[pRoot] > sz[qRoot])
                    {
                        parent[qRoot] = pRoot;
                        sz[pRoot] += sz[qRoot];  
                       
                    }
                    else
                    {
                        
                        parent[pRoot] = qRoot;
                        sz[qRoot] += sz[pRoot];
                      
                    }
                }
                else
                {
                    return ;
                }
       
            }
            
            bool isConnected(int p , int q)
            {
                return findRoot(p) == findRoot(q);
            }
            
            ~UnionFindSet()
            {
                delete[] this->parent;
                delete[] this->sz;
                count = 0;
            }
    };
}




#endif /* !__UNIONFINDSET_H__ */