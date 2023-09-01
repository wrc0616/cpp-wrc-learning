# cpp-wrc-learning
这是一个c++学习过程的笔记，以及找工作的一些笔记


## 数据结构
### map 哈希表
```cpp
//定义一个map
map<string,int> mymap;
unordered_map<string,int> mymap;

//添加元素
mymap['key'] = 25;

//访问元素
cout << "key: " << mymap["key"] << endl;

//修改元素
mymap['key'] = 100;

//删除元素
mymap.erase('key');

//遍历
map<std::string, int>::iterator it;
for (it = mymap.begin(); it != mymap.end(); ++it)
{
  std::cout << it->first << ": " << it->second << std::endl;
}

//查找
//find()用法
string target = "key"；
if(mymap.find(target)!=mymap.end())
{
  cout<<target<<"found in the map."<<endl;
}
//count()用法
if(mymap.count(traget)==1)
{
  cout<<target<<"found in the map."<<endl;
}

//长度
mymap.size();

//其他
empty() //查看是否为空
```



### Set 集合
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

//其他用法
clear()//清空集合
empty()//判断是否为空
swap()//交换两个集合的变量
lower_bound()//二分查找第一个不小于某个值的元素的迭代器
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


对撞双指针：两个指针面对面的移动 题: [881](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/881%20%E6%95%91%E7%94%9F%E8%89%87.cpp)


快慢双指针：慢指针+块指针  题：[141](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/141%20%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8.cpp)


###二分法查找法
题: [704]
