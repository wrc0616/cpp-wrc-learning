//分治法
class Solution {
public:
    //注意这里的left和right不能使用引用，会一直改变。
    int getmajority(vector<int> &nums,int left,int right)
    {
        //首先判断最后一个是不是一个值，不可以在分了
        if(left == right)
        {
            return nums[left];
        }
        //每次取中间值
        int mid = (left+right)/2;
        //进入递归，左边最多的值输出
        int leftmajority = getmajority(nums,left,mid);
        //进入递归，右边最多的值输出
        int rightmajority = getmajority(nums,mid+1,right);
        //如果左边的值等于右边的值，直接返回相等的这个值
        if(leftmajority==rightmajority)
        {
            return leftmajority;
        }
        int leftcount=0;
        int rightcount = 0;
        //如果不相等，判断那个值出现的多，就返回哪个值
        for(int i=left;i<=right;i++)
        {
            if(nums[i]==leftmajority)
            {
                leftcount++;
            }
            else if(nums[i]==rightmajority)
            {
                rightcount++;
            }
        }
        if(rightcount>leftcount)
        {
            return rightmajority;
        }
        else
        {
            return leftmajority;
        }
    }
    int majorityElement(vector<int>& nums) {
        return getmajority(nums,0,nums.size()-1);
    }
};

//哈希表法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mymap;
        int res=0;
        int count=0;
        for(int i:nums)
        {
            mymap[i]++;
            if(mymap[i]>count)
            {
                count = mymap[i];
                res = i;
            }
        }
        return res;
    }
};
//数学法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = (nums.size()-1)/2;
        return nums[n];
    }
};
