# cpp-wrc-learning
这是一个c++学习过程的笔记，以及找工作的一些笔记


## 数据结构
### Set

```cpp
// 定义一个 set
#include <set>
unordered_set<type> myset;
set<type> myset;

// 添加元素
myset.insert(元素);

//访问元素（set中的元素是有序的）
for(const int &num : myset){
  cout<<num<<endl;
}
//删除元素
myset.erase(元素)；

//查找元素
//find()用法
if(myset.find(target)!=myset.end())
{
  cout<<target<<"found in the set."<<endl;
}
//count()用法
if(myset.count(traget)==1)
{
  cout<<target<<"found in the set."<<endl;
}

//长度
myset.size();
//
1.创建
2.添加元素
3.访问元素
4.修改元素
5.删除元素
6.遍历
7.查找元素
8.长度
9.排序

```


## 算法
### 双指针
普通双指针：两个指针往同一方向移动


对撞双指针：两个指针面对面的移动


快慢双指针：慢指针+块指针  题：141
