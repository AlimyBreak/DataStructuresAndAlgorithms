


#ifndef __SPARSEGRAPH_H__
#define __SPARSEGRAPH_H__
#include <cassert>
#include <iostream>
#include <vector>
#include "WeightedEdge.h"
using namespace std;


/* 稀疏图-邻接表*/
template <typename Weight>
class SparseGraph
{
    private:
        int                             n           ;
        int                             m           ;
        bool                            directed    ;
        vector<vector<Edge<Weight>*>>   g           ;   /* 存储顶点*/
        
        
    public:
        SparseGraph(int n , bool directed)
        {
            this->n         = n         ;
            this->m         = 0         ;
            this->directed  = directed  ;
            for(int i = 0 ; i < n ;i++)
            {
                g.push_back(vector<Edge<Weight>*>()); /* 先压空的*/
            }
        }
        
        ~SparseGraph()
        {
            for(int i = 0 ; i < n ; i ++)
            {
                for(int j = 0 ; j < g[i].size() ; j++)
                {
                    delete g[i][j];
                }
            }
            
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
        
        /* 添加边 顶点v和顶点w 之间,允许平行边*/
        void addEdge(   int v, int w, Weight weight)
        {
           assert( v >= 0 && v <= n-1);
           assert( w >= 0 && w <= n-1);
           
           g[v].push_back(new Edge<Weight>(v,w,weight));
           if((v!=w)&&(directed==false)) /*防止自环边,自环边压一次就行了,无向图只要压一次就型了*/
           {
               g[w].push_back(new Edge<Weight>(w,v,weight));
           }
           m++;
        }
        
                
        /* 判断两个顶点之间是否有连接*/
        bool hasEdge(int v,int w)
        {
           assert( v >= 0 && v <= n-1);
           assert( w >= 0 && w <= n-1);
           
           for(int i = 0 ;i <g[v].size();i++)
           {
                if(g[v][i]->other(v) == w) /*判断是否有一个有,有一个有则直接返回true*/
                {
                    return true;
                }
           }
           return false;
        }
        
        
        void show(void)
        {
            cout << "I am a SparseGraph!" << endl;
            for(int i = 0 ; i < n;i++)
            {
                cout << "vertex " << i <<":\t";
                for(int j = 0 ; j < g[i].size();j++)
                {
                    //cout<<g[i][j]<<"\t";
                    cout << "( to:" << g[i][j]->w() << ",wt" << g[i][j]->wt() << ")\t";
                }
                cout << endl;
            }
        }
        
        
        
        /* 制作一个迭代器,用来表示某个节点的邻节点,邻边迭代器*/
        class adjIterator{
            private:
                SparseGraph&    G;
                int             v;     /* 节点位置     */
                int             index; /* 当前迭代位置 */
            public:
                adjIterator(SparseGraph& graph,int v):G(graph)
                {
                    this->v = v;
                    this->index = 0;
                }
                
                Edge<Weight>* begin() /* 第一个*/
                {
                    index = 0;
                    if(G.g[v].size()!=0)
                    {
                        return G.g[v][index];
                    }
                    return NULL;
                    
                }

                Edge<Weight>* next()
                {
                    index++;
                    if(index < G.g[v].size())
                    {
                        return G.g[v][index];
                    }
                    return NULL;
                    
                }
                bool end()
                {
                   return index >= G.g[v].size(); 
                }
                
        };
};


#endif /* !__SPARSEGRAPH_H__ */