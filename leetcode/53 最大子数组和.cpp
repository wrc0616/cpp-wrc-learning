//动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int max_val=nums[0];
        for(int i:nums)
        {
            //现在的值和先前加器起来的值哪个大
            pre=max(pre+i,i);
            //现在最大的值，和之前最大值比较
            max_val = max(max_val,pre);
        }
        return max_val;
    }
};
//分治法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return getmax(nums,0,nums.size()-1);
    }
    int getmax(vector<int>& nums,int left,int right)
    {
        if(left==right)
        {
            return nums[left];
        }
        int mid = (left+right)/2;
        int leftmax=getmax(nums,left,mid);
        int rightmax = getmax(nums,mid+1,right);
        int midmax = middlemax(nums,left,right);
        int twomax = max(leftmax,rightmax);
        return max(twomax,midmax);
    }
    int middlemax(vector<int> &nums,int left,int right)
    {
        int mid = (left+right)/2;
        int leftsum = 0;
        int rightsum = 0;
        int leftmax = nums[mid];
        int rightmax = nums[mid+1];
        for(int i=mid;i>=left;i--)
        {
            leftsum = leftsum+nums[i];
            leftmax = max(leftmax,leftsum);
        }
        for(int i=mid+1;i<=right;i++)
        {
            rightsum = rightsum+nums[i];
            rightmax = max(rightsum,rightmax);
        }
        return rightmax+leftmax;
    }
};
