
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "binarySearchTree.h"

using namespace std;


int main(void)
{
    BST<int,int> bst;
    int arr[10] = { 0,};
    for(int i = 0 ; i < 10 ; i ++)
    {
        arr[i] = i ;
        bst.insert(rand()%10,arr[i]);
    }
    
    
    cout << "前序遍历结果为:"<<endl;
    bst.preOrder();
    
    cout << "中序遍历结果为:"<<endl;
    bst.inOrder();
    
    cout << "后序遍历结果为:"<<endl;
    bst.postOrder();
    
    cout << "层序遍历结果为:" << endl;
    bst.levelOrder();
    

    return 0;
    
    
    
    

}
