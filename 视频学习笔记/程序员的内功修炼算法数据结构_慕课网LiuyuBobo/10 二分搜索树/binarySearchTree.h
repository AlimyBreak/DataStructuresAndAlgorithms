


#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__
#include <queue>  // 广度优先遍历需要用到队列

using namespace std;


template< typename Key , typename Value>
class BST{
  
  private:
    struct Node
    {
        Key     key     ;
        Value   value   ;
        Node*   left    ;
        Node*   right   ;
        Node(Key key,Value value) /* 节点构造函数*/
        {
            this->key   = key;
            this->value = value;
            this->left  = NULL;
            this->right = NULL;
        }
        Node(Node* node) /* 节点构造函数*/
        {
            this->key   = node->key;
            this->value = node->value;
            this->left  = node->left;
            this->right = node->right;
        }        
        
    };
  
  
    Node* root; /* 树根           */
    int count ; /* 用于计数       */
    
    Node* insert(Node* node, Key key , Value value)
    {
        /* 向以node为根的二叉搜索数插入一个键为key值为value的节点
           返回插入新节点后的二叉搜索数的根
        */
        if(node == NULL)
        {
            count++;
            return new Node(key,value); /* ????*/
        }
        if(key == node->key)
        {
            node->value = value;
        }
        else if(key < node->key)
        {
            node->left = insert(node->left,key,value);
        }
        else
        {
            node->right = insert(node->right,key,value);
        }
        return node;
    }
    
    bool contain(Node* node, Key key)
    {
        /*在以node为根的二叉搜索数中是否包含键为key的节点*/
        
        if(node == NULL) /* 递归到底 */
        {
            return false;
        }
        
        if(key == node->key)
        {
            return true;
        }
        else if(key < node->key)
        {
            return contain(node->left,key);
        }
        else 
        {
            return contain(node->right,key);            
        }
    }
    
    
    Value* search(Node* node, Key key)
    {
        /* 在以node为根的二叉搜索数中是否包含键为key的节点,
           若找到了返回对应value域的指针
           若没有找到返回NULL
        */
        if(node == NULL)
        {
            return NULL;
        }
        
        if(key == node->key)
        {
            return &(node->value);
        }
        else if (key < node->key)
        {
            return search(node->left,key);
        }
        else
        {
            return search(node->right,key);
        }   
    }
    
    /* 前序遍历: 中左右 对以node为根的二叉搜索树进行前序遍历 */
    void preOrder(Node* node)
    {
        if(node!=NULL)
        {
             cout << node->key << endl; // 中
             preOrder(node->left);      // 左
             preOrder(node->right);     // 右
        }
        else
        {
            return ;
        }
    }
    
    /*中序遍历: 左中右 对以node为根的二叉搜索树进行中序遍历 */
    void inOrder(Node* node)
    {
        if(node!=NULL)
        {
            inOrder(node->left);        // 左
            cout << node->key << endl;  // 中
            inOrder(node->right);       // 右
        }
        else
        {
            return ;
        }
        
    }
    
    /*后序遍历: 左右中,对以node为根的二叉搜索树进行后序排列*/
    void postOrder(Node* node)
    {
        if(node !=NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->key << endl;
        }
        else
        {
            return ;
        }
        
    }
    
    /* 释放以node为根节点的二叉搜素树(与后序遍历一致)*/
    void destoryTree(Node* node)
    {
        if(node!=NULL)
        {
            destoryTree(node->left);
            destoryTree(node->right);
            delete node;
            count--;
        }
        else
        {
            return ;
        }
    }
    
    /* 找到以node为根节点子树的左孩子节点,返回最小键值所在节点*/
    Node* minimum(Node* node)
    {
        if(node->left == NULL)
        {
            return node;
        }
        else
        {
            return minimum(node->left);
        } 
    }
    
    /* 找到以node为根节点子树的左孩子节点,返回最大键值所在节点*/
    Node* maximum(Node* node)
    {
        if(node->right == NULL)
        {
            return node;
        }
        else
        {
            return minimum(node->right);
        } 
    }
    
    
    /* 删除以node为根节点的二分搜素树中的最小节点,返回删除节点后新的二分搜索树的根*/
    Node* removeMin(Node* node)
    {
        if(node->left == NULL)
        {
            // 已经找到最小值
            Node* rightNode = node->right;
            delete node;
            count--;
            return rightNode; /* 其右孩子代替他成为原父节点的左孩子*/
        }
        else
        {
            node->left = removeMin(node->left);
        }
        
        return node;
    }
    
    /* 删除以node为根节点的二分搜素树中的最大节点,返回删除节点后新的二分搜索树的根*/
    Node* removeMin(Node* node)
    {
        if(node->right== NULL)
        {
            // 已经找到最大值
            Node* leftNode = node->left;
            delete node;
            count --;
            return leftNode; /* 其右孩子代替他成为原父节点的左孩子*/
        }
        else
        {
            node->right = removeMin(node->right);
        }
        
        return node;
    }
    
    
    /* 删除以node为根的二分搜索树中键值为key的节点,返回节点后新的二分搜索树的根*/
    Node* remove(Node* node,Key key)
    {
        if(node == NULL)
        {
            return NULL;
        }
        if(node->key == key)
        {
            if(node->left==NULL)
            {
                // 只有右孩子
                Node* rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            
            if(node->right==NULL)
            {
                // 只有左孩子
                Node* leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }
            
            Node* delNode = node;
            Node* rightMin = NULL;
            rightMin = new Node(minimum(node->right));    /* 虽然这里指向了,需要复制一份*/
            count++;
            rightMin ->right = removeMin(node->right); /*但在这里被删除了,里面执行了count--*/
            rightMin ->left = node->left;
            delete delNode;
            count--;
            return rightMin;         
            
        }
        else if(node->key < key)
        {
            node->right =remove(node->right,key)
        }
        else //node->key > key
        {
            node->left = remove(node->left,key);
        }
        
        return node;
    }
    
  public:
    BST()
    {
        root  = NULL;
        count = 0;
    }
    
    /* 插入新的节点 */
    void insert(Key key,Value value)
    {
        root = insert(root,key,value); /* 递归调用*/ 
    }
    
    /* 查找节点 */
    Value* search(Key key)
    {
        /* 到底返回什么 
            Node*   不够好,外部不必要了解
            Value   不够好,要是没找到,返回啥,要首先确认存在才能返回
            Value*  挺好,没找到就返回NULL,找到了就指向value
        */
        
        return search(root,key);
        
    }
    
    /* 节点是否存在 */
    bool contain(Key key)
    {
        return contain(root);
    }
    
    
    /* 深度优先遍历*/
    /* 前序遍历*/
    void preOrder()
    {
        preOrder(root);
    }
    
    /* 中序遍历*/
    void inOrder()
    {
        inOrder(root);
    }
    
    /* 后序遍历 */
    void postOrder()
    {
        postOrder(root);
    }
    
    /*广度优先遍历,层序遍历*/
    void levelOrder()
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) /* 直到队列为空*/
        {
            Node* node = q.front();
            q.pop();
            cout << node->key << endl;
            if(node->left!=NULL)
            {
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
        }
    }
    
    /* 找到最小的键值 */
    Key minimum()
    {
        assert(count != 0 );
        Node* node = minimum(root);
        return node->key;
    }
    
    /* 找到最大的键值 */
    Key maximum()
    {
        assert(count != 0 );
        Node* node = maximum(root);
        return node->key;
    }
    
    /* 删除最小值节点 */
    void removeMin()
    {
        if(root!=NULL)
        {
            root = removeMin(root);
        }
        else
        {
            return ;
        }
    }
    
    /* 删除最大值节点*/
    void removeMax()
    {
        if(root!=NULL)
        {
            root = removeMax(root)
        }
        {
            return ;
        }
    }
    
    /*从二叉树中删除键值为key的节点*/
    void remove(Key key)
    {
        
        
    }
    
   
    ~BST()
    {
       destoryTree(root);
       root = NULL;
    }
    
    /* 获取大小 */
    int getSize()
    {
        return count;
    }
    
    /* 是否为空 */
    bool isEmpty()
    {
        return (count == 0);
    }
  

};




#endif /* !__BINARYSEARCHTREE_H__ */

