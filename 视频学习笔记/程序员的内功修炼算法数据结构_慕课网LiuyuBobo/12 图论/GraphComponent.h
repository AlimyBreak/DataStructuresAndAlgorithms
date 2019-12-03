#ifndef __GRAPH_COMPONENT_H__
#define __GRAPH_COMPONENT_H__



#include <iostream>
#include <cassert>
using namespace std;

template <typename Graph>
class Component
{    
    private:
        Graph &G                ;
        bool* visited           ;   /* 记录节点是否被访问的数组指针*/
        int   component_count   ;   /* 记录图中有几个联通分量 */
        int*  component_id      ;   /* 记录每个节点的联通分量编号*/
        void dfs(int index)
        {
            visited[index]      = true;
            component_id[index] = component_count;
            typename Graph::adjIterator adj(G,index);
            for(int i = adj.begin();!adj.end();adj.next()) /*遍历邻边*/
            {
                if(!visited[i])
                {
                    dfs(i);
                }
            }
        }
    
    public:
        Component(Graph& graph):G(graph)
        {
            visited         = new bool[G.getVertexNum()]  ;
            component_id    = new int[G.getVertexNum()]   ;
            component_count = 0                           ;
            for(int i = 0 ; i < G.getVertexNum();i++)
            {
                visited[i]      = false ; /*默认都未被访问到 */
                component_id[i] = -1    ; /*默认未分组       */
            }
            
            /*遍历算法*/
            for(int i = 0 ; i < G.getVertexNum() ; i++ )
            {
                if(!visited[i])
                {
                    dfs(i);
                    component_count++;
                }
            }
        }
        
        ~Component()
        {
            delete[] visited;
            delete[] component_id;
        }
        
        

        
        /*获得连通分量个数*/
        int componentCount()
        {
            return component_count;
        }
        
        /*获取两个顶点之间是否连接的状态*/
        bool isConnected(int v,int w)
        {
            
            assert( v >= 0 && v < G.getVertexNum() );
            assert( w >= 0 && w < G.getVertexNum() );
            
            return (component_id[v] == component_id[w]);
        }
    
};




#endif // !__GRAPH_COMPONENT_H__