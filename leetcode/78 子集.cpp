//回溯法
class Solution {
public:
    void ziji(vector<int>& nums,vector<vector<int>> &result,int length,int index,vector<int> subset)
    {
        if (subset.size()==length)
        {
            result.push_back(subset);
        }

        for(int i =index;i<nums.size();i++)
        {
            subset.push_back(nums[i]);
            ziji(nums,result,length,i+1,subset);
            subset.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset={};
        result.push_back(subset);
        for(int i=1;i<=nums.size();i++)
        {
            ziji(nums,result,i,0,subset);
        }
        return result;
    }
};
