class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> rm(m,0);
        vector<int> cm(n,0);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    rm[i]=-1;
                    cm[j]=-1;
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(rm[i]==-1 || cm[j]==-1)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};