+ [慕课网连接](https://coding.imooc.com/class/chapter/71.html)
+ 程序员的内功修炼算法数据结构

#   第八章：带权图(Weighted Graph)
+ 边沿上的权：可以是个数字、字符串或更加复杂的数据包

## 如何表示带权图

+ 邻接矩阵(Adjacency Matrix):将矩阵的对应位置修改为权值，而未连接的部分赋值为0即可.
+ 邻接表(Adjacency Lists):记录数据将复杂一些，需要包含两个信息：连接节点和连接权值，重新定义Edge类。