
#ifndef __WEIGHTED_EDGE_H__
#define __WEIGHTED_EDGE_H__

#include <iostream>
//#include <ofstream>
#include <assert.h>

using namespace std;

template <typename Weight>
class Edge
{
    private:
        int     a       ;
        int     b       ;   /*两个节点的序号*/
        Weight  weight  ;   /*权值*/
        
    public:
        Edge(int a, int b , Weight weight)
        {
            this->a      = a        ;
            this->b      = b        ;
            this->weight = weight   ;
        }
        
        Edge()
        {
            
        }
        
        ~Edge()
        {
            
        }
        
        
        /*获取head节点序号*/
        int v()
        {
            return a;
        }
        
        /*获取tail节点序号*/
        int w()
        {
            return b;
        }
        
        /*获取权值*/
        Weight wt()
        {
            return weight;
        }
        
        /*获取另外一个顶点序号*/
        int other(int x)
        {
            assert( x==a || x==b);
            return x == a ? b : a;
        }
        
        /*重载 << ,便于输出信息 */
        friend ostream& operator<<(ostream& os, const Edge& e)
        {
            os << e.a << "-" << e.b << ": " << e.weight;
            return os;
        }
        /*重载比较运算符*/
        bool operator<(Edge<Weight>& e)
        {
            return weight < e.wt();
        }
        bool operator<=(Edge<Weight>& e)
        {
            return weight <= e.wt();
        }
        bool operator>(Edge<Weight>& e)
        {
            return weight > e.wt();
        }
        bool operator>=(Edge<Weight>& e)
        {
            return weight >= e.wt();
        }
        
        bool operator==(Edge<Weight>& e)
        {
            return weight == e.wt();
        }
        
        bool operator!=(Edge<Weight>& e)
        {
            return weight != e.wt();
        }
    
};


#endif //__WEIGHTED_EDGE_H__


