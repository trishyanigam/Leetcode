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
    int search(vector<int>& inorder,int left,int right,int val)
    {
        for(int i=left;i<=right;i++)
        {
            if(inorder[i]==val)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int& idx,int left,int right)
    {
        if(left>right)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[idx]);
        int inIdx = search(inorder,left,right,postorder[idx]);
        idx--;
        root->right=helper(inorder,postorder,idx,inIdx+1,right);
        root->left=helper(inorder,postorder,idx,left,inIdx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int idx=n-1;
        return helper(inorder,postorder,idx,0,n-1);
    }
};