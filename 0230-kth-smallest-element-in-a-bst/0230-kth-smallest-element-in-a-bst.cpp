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
    void helper(TreeNode* root,int k,int &kval,int &cnt)
    {
        if(root==NULL || cnt>=k)
        {
            return;
        }
        helper(root->left,k,kval,cnt);
        cnt++;
        if(cnt==k)
        {
            kval=root->val;
            return;
        }
        helper(root->right,k,kval,cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int kval=INT_MIN;
        int cnt=0;
        helper(root,k,kval,cnt);
        return kval;
    }
};