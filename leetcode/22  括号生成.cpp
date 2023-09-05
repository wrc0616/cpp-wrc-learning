//回溯法
class Solution {
public:
    void backtracking(int n, vector<string>& result, int left, int right, string str) {
        if (right > left || left > n || right > n) {
            return;
        }
        if (left == n && right == n) {
            result.push_back(str);
            return;
        }
        if (left < n) {
            backtracking(n, result, left + 1, right, str + '(');
        }
        if (left > right) {
            backtracking(n, result, left, right + 1, str + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtracking(n, result, 0, 0, "");
        return result;
    }
};
