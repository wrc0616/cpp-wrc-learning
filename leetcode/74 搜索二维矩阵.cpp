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
class Solution {
public:
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        //找到第一个矩阵行数【0】大于target的行数
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int> &a) {
            return b < a[0];
        });
        if (row == matrix.begin()) {
            return false;
        }
        --row;
        //
        return binary_search(row->begin(), row->end(), target);
    }
};



