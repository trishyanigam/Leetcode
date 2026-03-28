class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {      
        int r=matrix.size();
        int c=matrix[0].size();
        int low=0;
        int high=r*c-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int nr=mid/c;
            int nc=mid%c;
            if(matrix[nr][nc]==target)
            {
                return true;
            }
            else if(target<matrix[nr][nc])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return false;
    }
};