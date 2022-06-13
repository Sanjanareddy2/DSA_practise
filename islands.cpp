//https://leetcode.com/problems/number-of-islands/

 bool valid(int i, int j, int m,int n){
        if((i>=0)&&(i<m)&&(j>=0)&&(j<n))return true;
        return false;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>&visited,int i,int j, int m , int n){
        visited[i][j]=true;
        if(valid(i-1,j,m,n) && grid[i-1][j]=='1' && visited[i-1][j]==false)dfs(grid,visited,i-1,j,m,n);
        if(valid(i,j-1,m,n) && grid[i][j-1]=='1'&& visited[i][j-1]==false)dfs(grid,visited,i,j-1,m,n);
        if(valid(i+1,j,m,n) && grid[i+1][j]=='1'&& visited[i+1][j]==false)dfs(grid,visited,i+1,j,m,n);
        if(valid(i,j+1,m,n) && grid[i][j+1]=='1'&& visited[i][j+1]==false)dfs(grid,visited,i,j+1,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int isl = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    isl++;
                    dfs(grid,visited,i,j,m,n);
                }
            }
        }
        return isl;
        
    }