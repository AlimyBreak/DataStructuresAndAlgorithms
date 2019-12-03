

#ifndef __UNIONFINDSET2_H__
#define __UNIONFINDSET2_H__
#include <cassert>
#include <iostream>

using namespace std;

namespace UF2{
    
    class UnionFindSet
    {
        private:
            int*     parent     ;
            int      count  ;
        
        
        public:
            UnionFindSet(int n )
            {
                /* n 表示这个并查集有几何元素 */
                this->parent = new int[n]    ;
                this->count  = n             ;
                for(int i = 0 ; i < n ; i++)
                {
                    parent[i] = i; /* 初始化时,每个元素都指向自己,每个都是父节点*/
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
                    parent[pRoot] = qRoot;
                    
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
                count = 0;
            }
    };
}




#endif /* !__UNIONFINDSET_H__ */