class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>freq((n*n)+1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                freq[grid[i][j]]++;
            }
        }
        int rep=-1,mis=-1;
        for(int i=1;i<=n*n;i++)
        {
            if(freq[i]==2)
            {
                rep=i;
            }
            if(freq[i]==0)
            {
                mis=i;
            }
        }
        return {rep,mis};
    }
};