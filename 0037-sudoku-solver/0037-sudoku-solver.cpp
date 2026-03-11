class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int r,int c,int dig)
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
        int srow = (r/3)*3;
        int scol = (c/3)*3;
        for(int i=srow;i<=srow+2;i++)
        {
            for(int j=scol;j<=scol+2;j++)
            {
                if(board[i][j]==dig)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board,int r,int c)
    {
        if(r==9)
        {
            return true;
        }
        int nr=r;
        int nc=c+1;
        if(nc==9)
        {
            nr=r+1;
            nc=0;
        }
        if(board[r][c]!='.')
        {
            return helper(board,nr,nc);
        }
        for(char dig='1';dig<='9';dig++)
        {
            if(isSafe(board,r,c,dig))
            {
                board[r][c]=dig;
                if(helper(board,nr,nc))
                return true;
                board[r][c]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};