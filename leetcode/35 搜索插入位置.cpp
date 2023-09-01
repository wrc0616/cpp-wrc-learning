\\二分查找法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int mid = 0;
        int left = 0;
        int right = nums.size()-1;
        while(left<=right)
        {
            mid = (left+right)/2;
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
        
        return left;//返回为left，因为num[mid]是比target小，mid+1就是索引值，也就是left.
    }
};
