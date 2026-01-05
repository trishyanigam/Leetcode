class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long tot = 0;
        int neg=0;
        int minNeg = INT_MAX;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]<0)
                {
                    neg++;
                }
                tot+=abs(matrix[i][j]);
                minNeg = min(minNeg,abs(matrix[i][j]));
            }
        }

        if(neg%2==1)
        {
            tot = tot-(2LL*minNeg);
        }
    return tot;
    }
};