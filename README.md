# cpp-wrc-learning
这是一个c++学习过程的笔记，以及找工作的一些笔记


## 数据结构
### vector数组
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; // 引入命名空间 std
//定义一个vector
vector<int> myVector;
// 添加元素
myVector.push_back(42);
myVector.push_back(18);
myVector.push_back(7);
myVector.push_back(99);
// 访问元素
int firstElement = myVector[0];
cout << "First element: " << firstElement << endl;
// 修改元素
myVector[1] = 55;
// 删除元素
myVector.pop_back();
// 遍历元素
for (int element : myVector) {
  cout << element << " ";
}
// 查找元素
int target = 7;
vector<int>::iterator  iter=find(myVector.begin(), myVector.end(), target);
if(iter!=myVector.end())
	{	
		int index = distance(myVector.begin(),iter);
		cout << "Element " << target << " found at index " << index << endl;
		
	}
	else {
    cout << "Element " << target << " not found" << endl;
    }
// 使用 std::count 查找元素
int target = 7;
int count = std::count(myVector.begin(), myVector.end(), target);//count的值为target在数组中出现的次数
// 长度
int length = myVector.size();
cout << "Vector length: " << length << endl;
// 排序
sort(myVector.begin(), myVector.end());//默认从小到大
sort(myVector.begin(), myVector.end(),std::greater<int>());//从大到小
sort(myVector.begin(), myVector.end(),std::less<int>());//从小到大


```
### queue 队列
```cpp
#include <iostream>
#include <queue>

using namespace std;


// 1. 创建队列
queue<int> myQueue;

// 2. 添加元素
myQueue.push(42);

// 3. 访问元素
int frontElement = myQueue.front();
cout << "Front element: " << frontElement << endl;

// 4. 修改元素 - 队列通常不支持修改元素

// 5. 删除元素
myQueue.pop();

// 6. 遍历队列
myQueue.push(10);
myQueue.push(20);
myQueue.push(30);

while (!myQueue.empty()) {
	int element = myQueue.front();
	cout << "Element: " << element << endl;
	myQueue.pop();
}

// 7. 查找元素 - 队列通常不支持直接查找元素

// 8. 获取队列长度
int queueSize = myQueue.size();
cout << "Queue size: " << queueSize << endl;

// 9. 排序 - 队列不支持排序操作


```
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

### 滑动窗口

题 [209](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/209%20%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.cpp) 
、[1456](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/1456%20%20%E5%AE%9A%E9%95%BF%E5%AD%90%E4%B8%B2%E4%B8%AD%E5%85%83%E9%9F%B3%E7%9A%84%E6%9C%80%E5%A4%A7%E6%95%B0%E7%9B%AE.cpp)
### 递归
题 [509](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/509%20%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0.cpp)
、[206](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/206%20%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8.cpp)
### 分治法
题 [169](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/169%20%E5%A4%9A%E6%95%B0%E5%85%83%E7%B4%A0.cpp)
、[53](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/53%20%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E7%BB%84%E5%92%8C.cpp)
### 回溯法
题 [22](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/22%20%20%E6%8B%AC%E5%8F%B7%E7%94%9F%E6%88%90.cpp)
、[78](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/78%20%E5%AD%90%E9%9B%86.cpp)
### 深度优先算法（DFS）
题 [938](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/938%20%20%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E8%8C%83%E5%9B%B4%E5%92%8C.cpp)
、[200](https://github.com/wrc0616/cpp-wrc-learning/blob/main/leetcode/200%20%E5%B2%9B%E5%B1%BF%E6%95%B0%E9%87%8F.cpp)
### 广度优先算法（BFS）
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
