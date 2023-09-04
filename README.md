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


### 二分法查找法
题: [704](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/704%20%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.cpp)
、[35](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/35%20%E6%90%9C%E7%B4%A2%E6%8F%92%E5%85%A5%E4%BD%8D%E7%BD%AE.cpp)
、[162](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/162%20%E5%AF%BB%E6%89%BE%E5%B3%B0%E5%80%BC.cpp)

## c++的一些函数
- max_element()与min_element()
```cpp
#include <vector>
#include <iostream>
#include <algorithm>
vector<int> n;
int maxPosition = max_element(n.begin(),n.end()) - n.begin(); //最大值下标

int minPosition = min_element(n.begin(),n.end()) - n.begin();//最小值下标

2）普通数组
int a[]={1,2,3,4};
int maxPosition = max_element(a,a+2) - a; //最大值下标

int minPosition = min_element(a,a+2) - a;//最小值下标

// *max_element（）与*min_element（）分别用来求最大元素和最小元素的值。
// 接收参数：容器的首尾地址（迭代器）（可以是一个区间）
// 返回：最值元素的值

int maxValue = *max_element(n.begin(),n.end()); //最大值

int minValue = *min_element(n.begin(),n.end());//最小值

int maxValue = *max_element(a,a+2); //最大值

int minValue = *min_element(a,a+2);//最小值
```
- binary_search()
binary_search() 函数定义在<algorithm>头文件中，用于查找指定区域内是否包含某个目标元素。

该函数有 2 种语法格式，分别为：
```cpp
//查找 [first, last) 区域内是否包含 val
bool binary_search (ForwardIterator first, ForwardIterator last,
                      const T& val);
//根据 comp 指定的规则，查找 [first, last) 区域内是否包含 val
bool binary_search (ForwardIterator first, ForwardIterator last,
                      const T& val, Compare comp);
```
