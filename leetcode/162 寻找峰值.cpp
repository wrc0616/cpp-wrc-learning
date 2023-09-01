\\二分查找法
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            // 如果 mid 处于下坡，峰值在左侧
            //这里不能用mid-1这个操作，因为当只剩下两个数时，mid-1的值比left要小。有错误
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            }
            // 如果 mid 处于上坡，峰值在右侧
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};

//找到最大的值，max.
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return max_element(nums.begin(),nums.end())-nums.begin();
    }
};

//迭代的方法
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0;
        if(nums.size()==1)
        {
            return 0;
        }
        if(nums[0]>nums[1])
            {return 0;}
        if(nums[nums.size()-1]>nums[nums.size()-2])
        {
            return nums.size()-1;
        }
        for(i=1 ;i<nums.size()-1;i++)
        {
            
            if(nums[i-1]<nums[i]&&nums[i+1]<nums[i])
            {
                return i;
            }
        }
        return 0;
    }
};
