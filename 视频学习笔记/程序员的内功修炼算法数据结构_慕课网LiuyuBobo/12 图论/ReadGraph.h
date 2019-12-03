#ifndef  __READGRAPG_H__
#define  __READGRAPG_H__


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
#include "DenseGraph.h"
#include "SparseGraph.h"

using namespace std;


template <typename Graph>
class ReadGraph
{
    public:
        ReadGraph(Graph& graph,const string& filename)
        {
            ifstream file(filename);
            string line;
            int vertexNum; /*頂點數*/
            int edgeNum;   /*邊數*/
            
            assert( file.is_open() );
            assert(getline(file,line)); /*處理文件中的第一行*/
            stringstream ss(line);
            ss >> vertexNum >> edgeNum; /*點數和邊數*/
            
            assert(vertexNum == graph.getVertexNum()); /*點數應當一致*/
            
            for(int i = 0 ; i < edgeNum ; i++)
            {
                assert(getline(file,line));
                stringstream ss(line);
                int a,b;
                ss >> a >> b;
                /*檢查越界情況*/
                assert(a >=0 && a < vertexNum);
                assert(b >=0 && b < vertexNum);
                graph.addEdge(a,b);
            }
            
            
            
            
            
        }
    
};


#endif // !__READGRAPG_H__