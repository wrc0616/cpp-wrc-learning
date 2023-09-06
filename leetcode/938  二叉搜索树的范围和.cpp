//递归法
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void func(TreeNode* root,int &low,int &high,int &result)
    {
        if (root==nullptr)
        {
            return;
        }
        func(root->left,low,high,result);
        func(root->right,low,high,result);
        if(root->val<=high && root->val>=low)
        {
            result = result+root->val;
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int result=0;
        func(root,low,high,result);
        return result;

    }
};

//广度优先搜索
//使用队列来实现
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty())
        {
           int size=q.size();
           while(size>0)
           {
               auto cur=q.front();
               q.pop();
               if(cur->val>=low&&cur->val<=high)
               {
                   sum = sum+cur->val;
               }
               if(cur->left!=nullptr)
               {q.push(cur->left);}
               if(cur->right!=nullptr)
               {q.push(cur->right);}
               size--;
           }
        }
        return sum;
    }
};
