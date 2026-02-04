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
    int ans;
    int maxLevel = -1;
    void helper(TreeNode* root,int level)
    {
        if(root==NULL)
        {
            return;
        }
        if(level>maxLevel)
        {
            ans = root->val;
            maxLevel = level;
        }
        helper(root->left,level+1);
        helper(root->right,level+1);

    }
    int findBottomLeftValue(TreeNode* root) {
        helper(root,0);
        return ans;
    }
};