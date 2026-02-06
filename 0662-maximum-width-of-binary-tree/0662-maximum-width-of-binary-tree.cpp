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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty())
        {
            long st=q.front().second;
            long end=q.back().second;
            ans=max(ans,(int)(end-st+1));
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                auto node = q.front();
                q.pop();
                if(node.first->left)
                {
                    q.push({node.first->left,2*node.second+1});
                }
                if(node.first->right)
                {
                    q.push({node.first->right,2*node.second+2});
                }
            }
        }
        return ans;
    }
};