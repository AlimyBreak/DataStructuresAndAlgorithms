#include <time.h>
#include "SparseGraph.h"
#include "DenseGraph.h"

using namespace std;

int main1()
{
    int N = 20;
    int M = 100;
    int count = 0;
    
    srand(time(NULL));
    
    
    /* SparseGraph*/
    SparseGraph g1(N,false);
    for(int i = 0 ; i < M ;i++)
    {
        int a = rand() % N;
        int b = rand() % N;
        g1.addEdge(a,b);    /* 随机生成一张图*/
    }
    count = 0;
    cout << "SparseGraph:" << endl;
    for(int v = 0; v < N;v++)
    {
        cout << v << ":";
        SparseGraph::adjIterator adj(g1,v);
        for(int w = adj.begin();!adj.end();w=adj.next())
        {
            cout << w << "   ";
            count++;
        }
        cout << endl;
    }
    
    cout << "edge nums = " << count <<endl;

    
    

    DenseGraph g2(N,false);
    for(int i = 0 ; i < M ;i++)
    {
        int a = rand() % N;
        int b = rand() % N;
        g2.addEdge(a,b);
    }
    
    cout << "DenseGraph:" << endl;
    count = 0;
    for(int v = 0; v < N;v++)
    {
        cout << v << ":";
        DenseGraph::adjIterator adj2(g2,v);
        for(int w = adj2.begin();!adj2.end();w=adj2.next())
        {
            cout << w << "   ";
            count++;
        }
        cout << endl;
    }
    
    cout << "edge nums = " << count <<endl;
    
    return 0;
    
}

#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

int main2(void)
{
    string filename = "testG1.txt";
    
    SparseGraph g1(10,false);
    DenseGraph  g2(10,false);
    
    ReadGraph<SparseGraph> readGraph1(g1,filename);
    ReadGraph<DenseGraph>  readGraph2(g2,filename);
    
    g1.show();
    g2.show();
    
    
    
    return 0 ;
    
}

/* 测试图的dfs*/
#include "GraphComponent.h"
int main3(void)
{
    string filename1 = "testG2.txt";
    SparseGraph g1 = SparseGraph(10,false);
    DenseGraph  g2 = DenseGraph(10,false);
    
    ReadGraph<SparseGraph> readGraph1(g1,filename1);
    ReadGraph<DenseGraph>  readGraph2(g2,filename1);
    
    Component<SparseGraph> component1(g1);
    Component<DenseGraph>  component2(g2);
    
    cout << filename1 << " ,SparseGraph Component Count :" << component1.componentCount() << endl;
    cout << filename1 << " ,DenseGraph  Component Count :" << component2.componentCount() << endl;
    
    return 0;
}


/*测试寻路*/
#include "GraphPath.h"
int main4(void)
{
    string filename1 = "testG3.txt";
    SparseGraph g1 = SparseGraph(10,false);
    DenseGraph  g2 = DenseGraph(10,false);
    
    ReadGraph<SparseGraph> readGraph1(g1,filename1);
    ReadGraph<DenseGraph>  readGraph2(g2,filename1);    
    
    Path<SparseGraph> path1(g1,0);
    Path<DenseGraph>  path2(g2,0);    
    
    
    path1.showPath(5);
    path2.showPath(8);
    
    
    return 0;
   
}


/*测试广度优先搜索及最短路径*/
#include "shortestPath.h"
int main(void)
{
    string filename1 = "testG4.txt";
    SparseGraph g1 = SparseGraph(10,false);
    DenseGraph  g2 = DenseGraph(10,false);
    ReadGraph<SparseGraph> readGraph1(g1,filename1);
    ReadGraph<DenseGraph>  readGraph2(g2,filename1); 
    
    
    Path<SparseGraph> path1(g1,0);
    Path<DenseGraph>  path2(g2,0);    
    
    cout << "SparseGraph DFS:" << endl;
    path1.showPath(6);
    cout << "DenseGraph DFS:" << endl;
    path2.showPath(7);
    
    
    ShortestPath<SparseGraph> sp1(g1,0);
    ShortestPath<DenseGraph>  sp2(g2,0);
    
    cout << "SparseGraph BFS:"<< sp1.length(6) << endl;
    sp1.showPath(6);
    
    
    cout << "DenseGraph BFS:"<< sp2.length(7) << endl;
    sp2.showPath(7);
    
    
    
    
    return 0;
    
}