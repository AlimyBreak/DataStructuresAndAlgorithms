+ [慕课网连接](https://coding.imooc.com/class/chapter/71.html)
+ 程序员的内功修炼算法数据结构

#   第六章：并查集(Union Find)
+ 一种不一样的树形结构，体会解决不同的问题，在数据结构的设计有哪些不同

+ 在图论算法中将广泛应用到。

+ 研究的问题：连接问题(Connectivity Problem):

+ 研究网络中节点间的连接状态(网络是个抽象的概念：如用户之间形成的网络)

+ 实现数学中的集合类实现(set数据结构)

  ***

  + 连接问题和路径问题比较：连接问题比路径问题需要回答的问题太少，解决问题的算法将更高效。
  + 二分查找和顺序查找:顺序查找更慢，因为他不仅仅解决了查找数据的问题，还解决了数据的排名问题（Rank），还把查找到数据之前的数据的排名也解决了。
  + 在任意数组中找出排名n的数据，快速排序可以设计出O(n)的该算法，若先排序后再取，排序好不仅能解决排名n的问题，任意一个排名都能知道，所以更慢。
  + 堆中找到最值的高效在于：只关于问题本身。
  + ^我们实现的算法是否解决了多余的问题^？



## 并查集的实现

+ 并查集的基本操作：union(p,q),find(p)
+ 利用基本操作能解决的问题：isConnected(p,q)
+ 数据表示方式: 索引id，连接关系(连接在一起的数据其对应数据值相等)



### 数组形式

+ Quick Find:每个组直接用索引对应的值即可,O(1)

利用QuickFind能够很快的进行isConnected的判断

在Quick Find下进行Union，时间复杂度为O(n)

 方法一测试结果：UF1,20000 ops, 0.285；UF1,200000 ops, 10.503

非常慢，得想想办法啊。整体还是O(n^2^)

+ quick find在查找时很快，但在union时很慢，并查集的另外一种实现思路：

  把每一个元素看成一个节点，用指针连接，子节点指向父节点，父节点指向自己，若要合并两个集合只要让一个集合的根节点指向另外一个集合的根节点即可。

  Quick Union 在Union上很快。。

  Quick Union 测试结果：

  UF1,20000 ops, 0.271
  UF2,20000 ops, 0.083

  UF1,200000 ops, 10.104
  UF2,200000 ops, 9.505

  用10000测试，效果挺好，在100000下测试优化效果一般。

### 继续优化(基于Size)：

容易出现的问题：数据量比较大时，追溯根节点的过程将非常大，树非常高，要根据树的高度来进行指向修改。添加sz数组，进行维护。

测试结果：

UF1,200000 ops, 10.152
UF2,200000 ops, 9.582
UF3,200000 ops, 0.032

非常nice，优点时间复杂度大大降低，而需要额外开一倍的空间。

但在某些极端情况下，UF3依然存在问题。

### 极端情况：

层数多但节点少的集合与层数少但节点多的集合进行union，我们希望层数少的并到层数多的去，而不是单纯节点数多的并到节点数少的去。

优化方向：基于rank的优化，rank[i]表示根节点为i的树的高度。但只在极端情况下用起来比UF3好，但在非极端情况下，由于比较次数更多了，效率未必比UF3高。

测试结果：

UF1,200000 ops, 9.447
UF2,200000 ops, 9.235
UF3,200000 ops, 0.015
UF4,200000 ops, 0.016





## 路径压缩(Path Compression)

前几种优化主要集中在Union这个操作，但其实Find这个操作也是可以优化的。

重新构建根：我的父亲的父亲不是根，那我就把父亲的父亲当作根，直到父亲是根。

Todo(路径压缩后,rank已经不能准确表示树的高度了，为啥不需要特殊维护)



递归写法：

将子节点递归的连接到根节点上去。但由于递归开销，效率不一定优于上面的。

并查集的操作：时间复杂度近乎是O(1)的。

测试效果：

UF1,200000 ops, 9.944
UF2,200000 ops, 9.408
UF3,200000 ops, 0.022
UF4,200000 ops, 0.02
UF5(递归版本),200000 ops, 0.014

