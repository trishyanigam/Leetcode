class Solution {
public:
    bool dfs(vector<vector<char>> &board,int i,int j,int idx,string word,int n,int m)
    {
        if(idx==word.size())
        {
            return true;
        }

        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[idx])
        {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board,i-1,j,idx+1,word,n,m) ||
                     dfs(board,i+1,j,idx+1,word,n,m) ||
                     dfs(board,i,j-1,idx+1,word,n,m) ||
                     dfs(board,i,j+1,idx+1,word,n,m);

        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(board,i,j,0,word,n,m))
                {
                    return true;
                }
            }
        }
        return false;
    }
};