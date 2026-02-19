class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j,int old,int newColor)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=old || image[i][j]==newColor)
        {
            return;
        }
        image[i][j]=newColor;
        dfs(image,i-1,j,old,newColor);
        dfs(image,i+1,j,old,newColor);
        dfs(image,i,j-1,old,newColor);
        dfs(image,i,j+1,old,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};