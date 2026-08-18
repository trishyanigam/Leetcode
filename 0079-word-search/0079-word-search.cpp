class Solution {
public:
    bool dfs(int i,int j,int n,int m,vector<vector<char>>& board, string& word,int idx)
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
        bool found = dfs(i-1,j,n,m,board,word,idx+1) || 
                     dfs(i,j+1,n,m,board,word,idx+1) ||
                     dfs(i+1,j,n,m,board,word,idx+1) ||
                     dfs(i,j-1,n,m,board,word,idx+1);
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
                if(dfs(i,j,n,m,board,word,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};