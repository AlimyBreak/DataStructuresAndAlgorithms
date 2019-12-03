

#ifndef __DENSEGRAPH_H__
#define __DENSEGRAPH_H__
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// 稠密图 - 邻接矩阵
class DenseGraph
{
    private:
        int                     n           ; /* 图的点数               */
        int                     m           ; /* 图的边数               */
        bool                    directed    ; /* 是否有向               */
        vector<vector<bool>>    g           ; /* 邻接矩阵是个二维数组     */
    
    public:
        DenseGraph(int n , bool directed)
        {
            this->n         = n         ;
            this->m         = 0         ;
            this->directed  = directed  ;
            for(int i = 0 ; i < n;i++)
            {
                g.push_back(vector<bool>(n,false)); /* 默认都是未连接*/
            }
        }
        
        ~DenseGraph()
        {
            return ;
        }
        
        /* 获取顶点数*/
        int getVertexNum()
        {
            return n;
        }
        /* 获取边数*/
        int getEdgeNum()
        {
            return m;
        }
        
        /* 添加边 顶点v和顶点w 之间,平行边将被合并*/
        void addEdge(   int v, int w)
        {
           assert( v >= 0 && v <= n-1);
           assert( w >= 0 && w <= n-1);
           
           if(hasEdge(v,w)==true)
           {
               return ;
           }
           
           /* 平行边全被合并*/
           g[v][w] = true;
           if(!directed) /* 若为无向图,则转置对应位置也要设置*/
           {
               g[w][v] = true;
           }
           m++;
        }
        
        /* 判断两个顶点之间是否有连接*/
        bool hasEdge(int v,int w)
        {
           assert( v >= 0 && v <= n-1);
           assert( w >= 0 && w <= n-1);
           return g[v][w];
        }
        
        void show()
        {
            cout << "I am a DenseGraph!" << endl;
            for(int i = 0 ; i < n;i++)
            {
                cout << "vertex " << i <<":\t";
                for(int j = 0 ; j < n ;j++)
                {
                    if(g[i][j]==true)
                    {
                        cout << j << "\t";
                    }
                }
                
                cout << endl;
            }
        }
        
        /* 制作一个迭代器,用来表示某个节点的邻节点,邻边迭代器*/
        class adjIterator
        {
            private:
                DenseGraph&    G;      /* 图的引用*/
                int            v;     /* 节点位置 */
                int            index; /*当前迭代位置*/
            public:
                adjIterator(DenseGraph& graph,int v):G(graph)
                {
                    this->v     = v;
                    this->index = 0;
                }
                
                int begin() /* 第一个*/
                {
                    index = -1;
                    return next();
                }
                int next()
                {
                    for(index+=1;index < G.getVertexNum();index++)
                    {
                        if(G.g[v][index] == true)
                        {
                            return index;
                        }
                    }
                    return -1;
                }
                bool end()
                {
                   return index >= G.getVertexNum(); 
                }
        };
};



#endif /* !__DENSEGRAPH_H__*/