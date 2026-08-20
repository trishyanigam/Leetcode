class Solution {
public:
    bool isSafe(char dig,int r,int c,vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][c]==dig)
            {
                return false;
            }
        }
        for(int j=0;j<9;j++)
        {
            if(board[r][j]==dig)
            {
                return false;
            }
        }
        int sr = (r/3)*3;
        int sc = (c/3)*3;
        for(int i=sr;i<=sr+2;i++)
        {
            for(int j=sc;j<=sc+2;j++)
            {
                if(board[i][j]==dig)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(int r,int c,vector<vector<char>>& board)
    {
        if(r==9)
        {
            return true;
        }
        int nr = r;
        int nc = c+1;
        if(nc==9)
        {
            nr=r+1;
            nc=0;
        }
        if(board[r][c]!='.')
        {
            return helper(nr,nc,board);
        }
        for(char dig='1';dig<='9';dig++)
        {
            if(isSafe(dig,r,c,board))
            {
                board[r][c] = dig;
                if(helper(nr,nc,board))
                {
                    return true;
                }
                board[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(0,0,board);
    }
};