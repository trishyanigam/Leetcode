class Solution {
public:
    bool dfs(vector<vector<char>>& board,int i,int j,int n,int m,int idx,string word)
    {
        if(idx==word.size())
        {
            return true;
        }
        if(i<0||j<0||i>=n||j>=m||board[i][j]!=word[idx])
        {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board,i-1,j,n,m,idx+1,word) ||
                     dfs(board,i+1,j,n,m,idx+1,word) ||
                     dfs(board,i,j-1,n,m,idx+1,word) ||
                     dfs(board,i,j+1,n,m,idx+1,word);
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(board,i,j,n,m,0,word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};