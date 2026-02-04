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
    void helper(TreeNode* root,int level,vector<int>&res)
    {
        if(root==NULL)
        {
            return;
        }
        if(res.size()==level)
        {
            res.push_back(root->val);
        }
        helper(root->left,level+1,res);
        helper(root->right,level+1,res);

    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> res;
        helper(root,0,res);
        int n=res.size();
        return res[n-1];
    }
};