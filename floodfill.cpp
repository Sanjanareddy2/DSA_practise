//https://leetcode.com/problems/flood-fill/

bool valid(int i, int j, int m,int n){
        if((i>=0)&&(i<m)&&(j>=0)&&(j<n))return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited, int i, int j, int newColor, int s, int m ,int n){
        visited[i][j] = true;
        grid[i][j] = newColor;
        if(valid(i-1,j,m,n) && grid[i-1][j]==s && visited[i-1][j]==false)dfs(grid,visited,i-1,j,newColor,s,m,n);
        if(valid(i,j-1,m,n) && grid[i][j-1]==s && visited[i][j-1]==false)dfs(grid,visited,i,j-1,newColor,s,m,n);
        if(valid(i+1,j,m,n) && grid[i+1][j]==s && visited[i+1][j]==false)dfs(grid,visited,i+1,j,newColor,s,m,n);
        if(valid(i,j+1,m,n) && grid[i][j+1]==s && visited[i][j+1]==false)dfs(grid,visited,i,j+1,newColor,s,m,n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(),n=image[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        dfs(image,visited,sr,sc,newColor,image[sr][sc],m,n);
        return image;
    }