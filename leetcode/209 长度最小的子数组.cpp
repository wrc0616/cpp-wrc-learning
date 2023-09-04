class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int total = 0;
        int res = nums.size()+1;
        //滑动窗口的左右两端
        int left = 0;
        int right = 0;
        if (nums.size()==0)
        {return 0;}
        while(right<nums.size())
        {
            total = total + nums[right];
            while(total>=target)
            {
                res = min(res,right-left+1);
                total = total - nums[left];
                left++;
            }
            right++;
        }
        if(res == nums.size()+1)
        {
            return 0;
        }
        else
        {
            return res;
        }
    }
};
