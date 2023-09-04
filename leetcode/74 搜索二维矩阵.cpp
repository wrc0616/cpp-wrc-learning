//一次二分查找法
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //计算矩阵的行m和列n
        int m=matrix.size();
        int n = matrix[0].size();
        int left = 0;
        //一共有多少个元素
        int right = m*n-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            //计算中间值索引在矩阵中的值
            int mid_value = matrix[mid/n][mid%n];
            if(mid_value>target)
            {
                right = mid-1;
            }
            else if(mid_value<target)
            {
                left = mid+1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

//方法二  二次二分查找法
