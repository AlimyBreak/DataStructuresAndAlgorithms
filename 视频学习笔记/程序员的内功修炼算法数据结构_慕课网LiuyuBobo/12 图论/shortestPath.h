#ifndef __SHORTEST_PATH_H__
#define __SHORTEST_PATH_H__



#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

template <typename Graph>
class ShortestPath
{    
    private:
        Graph &G                ;
        int   s                 ;   /* 源节点                          */
        bool* visited           ;   /* 记录节点是否被访问的数组指针    */
        int*  from              ;   /* 记录每个节点被访问时的前驱节点  */
        int*  ord               ;   /* 记录当前节点到源节点的层数      */
        
        void bfs()
        {
            queue <int> q;
            q.push(s); /* 压入源点*/
            visited[s] = true;
            ord[s] = 0 ;
            
            while(!q.empty())
            {
                //首先取出队首元素
                int v = q.front();
                q.pop();
                
                //遍历所有相邻元素并入队伍
                typename Graph::adjIterator adj(G,v);
                for(int i = adj.begin() ; !adj.end() ; i = adj.next())
                {
                    if(!visited[i])
                    {
                        q.push(i);
                        visited[i] = true;
                        from[i]    = v;
                        ord[i]     = ord[v]+1;
                    }
                }
            }
            
            
        }

    public:
        ShortestPath(Graph& graph,int s):G(graph)
        {
            
            assert( s >= 0 && s < G.getVertexNum());
            
            visited         = new bool[G.getVertexNum()]  ;
            from            = new int[G.getVertexNum()]   ;
            ord             = new int[G.getVertexNum()]   ;
            
            for(int i = 0 ; i < G.getVertexNum();i++)
            {
                visited[i]      = false ; /*默认都未被访问到             */
                from[i]         = -1    ; /*默认都是未被访问无合法前驱   */
                ord[i]          = -1    ; /*默认都未被bfs,无合法层数     */
            }
            this->s = s;
            
            // 广度优先搜索
            bfs();
        }
        
        
        /* s <--> w  有无path */
        bool hasPath(int w)
        {
            assert( w >= 0 && w < G.getVertexNum() );
            return visited[w]; 
        }
        
        /* s<--->w 获取路径,存放到vec中去*/
        void getPath(int w,vector<int>& vec)
        {
            if(hasPath(w))
            {
               /* 倒推过程,需要stack辅助*/
               stack<int> st;
               
               int p = w;
               
               while(p!=-1) /*到-1就停止*/
               {
                   st.push(p);
                   p = from[p];
               }
               
               vec.clear();
               while(!st.empty())
               {
                   vec.push_back(st.top());
                   st.pop();
               }
            }
            
        }
        
        /* s<-->w 打印出路径*/
        void showPath(int w)
        {
            vector<int> vec;
            getPath(w,vec);
            for(int i = 0 ; i < vec.size() ; i++)
            {
                cout << vec[i];
                if(i== vec.size() -1 )
                {
                    cout << endl;
                }
                else
                {
                    cout << " -->  " ;
                }
            }
            
        }
        
        int length(int w)
        {
            assert( w >= 0 && w < G.getVertexNum() );
            return ord[w];
        }
        
        
        ~ShortestPath()
        {
            delete[] visited;
            delete[] from;
            delete[] ord;
        }

    
};




#endif // !__SHORTEST_PATH_H