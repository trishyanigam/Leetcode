class Solution {
public:
    bool check(int r,int c,int val,int n,vector<vector<int>>&grid)
    {
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=val)
        {
            return false;
        }
        if(val==(n*n-1))
        {
            return true;
        }
        bool ans1 = check(r-2,c-1,val+1,n,grid);
        bool ans2 = check(r-2,c+1,val+1,n,grid);
        bool ans3 = check(r-1,c+2,val+1,n,grid);
        bool ans4 = check(r+1,c+2,val+1,n,grid);
        bool ans5 = check(r+2,c+1,val+1,n,grid);
        bool ans6 = check(r+2,c-1,val+1,n,grid);
        bool ans7 = check(r+1,c-2,val+1,n,grid);
        bool ans8 = check(r-1,c-2,val+1,n,grid);

        return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        return check(0,0,0,n,grid);
    }
};