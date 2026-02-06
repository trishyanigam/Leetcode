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
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int s=q.size();
            unsigned long long st=q.front().second;
            unsigned long long end=q.back().second;
            ans=max(ans,(int)(end-st+1));
            for(int i=0;i<s;i++)
            {
                auto currNode=q.front();
                q.pop();
                TreeNode* node = currNode.first;
                int idx = currNode.second;
                if(node->left)
                {
                    q.push({node->left,2*idx+1});
                }
                if(node->right)
                {
                    q.push({node->right,2*idx+2});
                }
            }
        }
        return ans;
    }
};