

#ifndef __UNIONFINDSET4_H__
#define __UNIONFINDSET4_H__
#include <cassert>
#include <iostream>

using namespace std;

namespace UF4{
    
    class UnionFindSet
    {
        private:
            int*     parent     ;
            int*     rank       ; /*以i为根的集合中树的高度*/
            int      count      ;
        public:
            UnionFindSet(int n)
            {
                /* n 表示这个并查集有几何元素 */
                this->parent    =   new int[n]    ;
                this->rank      =   new int[n]    ;
                this->count     =   n             ;
                for(int i = 0 ; i < n ; i++)
                {
                    parent[i]   = i; /* 初始化时,每个元素都指向自己,每个都是父节点*/
                    rank[i]     = 1; /* 初始化时都指向自己,高度都是1*/ 
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
                    if(rank[pRoot] < rank[qRoot])
                    {
                        parent[pRoot] = qRoot;
                    }
                    if(rank[qRoot] < rank[pRoot])
                    {
                        parent[qRoot] = pRoot;
                    }
                    else // rank[qRoot] == rank[pRoot]
                    {
                        parent[pRoot] = qRoot;
                        rank[qRoot] += 1;
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
                delete[] this->rank;
                count = 0;
            }
    };
}




#endif /* !__UNIONFINDSET_H__ */