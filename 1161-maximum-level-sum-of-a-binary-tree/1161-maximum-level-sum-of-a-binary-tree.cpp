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
    int maxLevelSum(TreeNode* root) {
        int ans=0;
        int sum=INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int lvl=1;
        while(!q.empty())
        {
            int s=q.size();
            int currSum=0;
            for(int i=0;i<s;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                currSum+=node->val;
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            if(currSum>sum)
            {
                sum=currSum;
                ans=lvl;
            }
            lvl++;
        }
        return ans;
    }
};