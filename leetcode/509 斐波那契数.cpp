//方法一 递归方式
class Solution {
public:
    int fun(const int n)
    {
        if(n<2)
        {
            return n;
        }
        int m = 0;
        m = fun(n-1)+fun(n-2);
        return m;
        
    }
    int fib(int n) {
        int vale=0;
        vale = fun(n);
        return vale;
    }
};
//动态规划
class Solution {
public:
    int fib(int n) {
        int left=0;
        int right = 1;
        int sum = left+right;
        //n为2开始
        for(int i =2;i<n;i++)
        {
            left = right;
            right =sum;
            sum = left+right;  
        }
        return sum;
    }
};
