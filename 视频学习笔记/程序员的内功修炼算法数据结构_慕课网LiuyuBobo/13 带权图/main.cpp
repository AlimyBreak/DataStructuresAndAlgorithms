

#include <iomanip> //主要是对cin,cout之类的一些操纵运算子，比如setfill,setw,setbase,setprecision等等
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"

using namespace std;


int main(void)
{
    string filename = "testG1.txt";
    int V = 8;
    cout << fixed << setprecision(2);
    
    
    // Test Weighted Dense Graph
    DenseGraph<double> g1 = DenseGraph<double>(V,false);
    ReadGraph<DenseGraph<double>,double> readGraph1(g1,filename);
    g1.show();
    cout << endl;
    
    SparseGraph<double> g2 = SparseGraph<double>(V,false);
    ReadGraph<SparseGraph<double>,double> readGraph2(g2,filename);
    g2.show();
    cout << endl;
    
    
    
    return 0;
    
}