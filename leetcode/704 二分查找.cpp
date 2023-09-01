//暴力法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int j=0;
        for(auto i:nums)
        {
            if(i == target)
            {
                return j;
            }
            j++;
        }
        return -1;
    }
};


//二分法
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int mid=0;
        int left =0;
        int right = nums.size()-1;
        while(left<=right)
        {
            mid = (right+left)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return -1;
    }
};
或者
class Solution {
public:
    int search(vector<int>& nums, int target) {
    int j=0;
    int left=0;
    int right = nums.size()-1;
    j = (right + left) / 2;
    while(nums[j]!=target)
    {
        
        if(nums[j]>target)
        {
            right=j-1;
        }
        else
        {
            left = j+1;
        }
        if(left>right)
        {
            return -1;
        }
        j = (right + left) / 2;
    }
    return j;
    }
};



