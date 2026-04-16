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
    int search(int l,int r, vector<int>& inorder,int val)
    {
        for(int i=l;i<=r;i++)
        {
            if(inorder[i]==val)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int &idx,int l,int r)
    {
        if(l>r)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[idx]);
        int inidx = search(l,r,inorder,preorder[idx]);
        idx++;
        root->left = helper(preorder,inorder,idx,l,inidx-1);
        root->right = helper(preorder,inorder,idx,inidx+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return helper(preorder,inorder,idx,0,preorder.size()-1);
    }
};