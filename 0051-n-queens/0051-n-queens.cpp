class Solution {
public:
    bool isSafe(vector<string>&board,int r,int c,int n)
    {
        for(int j=0;j<n;j++)
        {
            if(board[r][j]=='Q')
            {
                return false;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(board[i][c]=='Q')
            {
                return false;
            }
        }

        for(int i=r,j=c;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }

        for(int i=r,j=c;i>=0&&j<n;i--,j++)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }

        return true;
    }
    void helper(int r,int n,vector<string>&board,vector<vector<string>>&ans)
    {
        if(r==n)
        {
            ans.push_back({board});
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(isSafe(board,r,j,n))
            {
                board[r][j]='Q';
                helper(r+1,n,board,ans);
                board[r][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        helper(0,n,board,ans);
        return ans;
    }
};