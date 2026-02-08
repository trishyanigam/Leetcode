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
    int maxLevel=-1;
    void helper(TreeNode* root,int level,int& ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(level>maxLevel)
        {
            maxLevel=level;
            ans=root->val;
        }
        helper(root->left,level+1,ans);
        helper(root->right,level+1,ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        helper(root,0,ans);
        return ans;
    }
};