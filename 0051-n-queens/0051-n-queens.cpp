class Solution {
public:
    bool isSafe(int r,int c,int n,vector<string>& board)
    {
        for(int i=0;i<n;i++)
        {
            if(board[i][c]=='Q')
            {
                return false;
            }
        }
        for(int j=0;j<n;j++)
        {
            if(board[r][j]=='Q')
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
    void helper(int i,int n,vector<string>& board,vector<vector<string>>& ans)
    {
        if(i==n)
        {
            ans.push_back({board});
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(isSafe(i,j,n,board))
            {
                board[i][j] = 'Q';
                helper(i+1,n,board,ans);
                board[i][j] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n,string(n,'.'));
        helper(0,n,board,ans);
        return ans;
    }
};