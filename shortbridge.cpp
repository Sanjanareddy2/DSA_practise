//https://leetcode.com/problems/shortest-bridge/

void make2(vector<vector<int>>& grid,int i, int j, int n){
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]!=1){
            return ;
        }
        grid[i][j]=2;
        make2(grid,i+1,j,n);
        make2(grid,i-1,j,n);
        make2(grid,i,j+1,n);
        make2(grid,i,j-1,n);
    }
    bool makec(vector<vector<int>>& grid,int i, int j, int n,int c){
        if(i<0 || j<0 || j>=n || i>=n) return false;
        if(grid[i][j]==1) return true;
        grid[i][j] = grid[i][j]==0? c+1 : grid[i][j];
        return false;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool flag = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    make2(grid,i,j,n);
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        for(int c = 2;;c++){
            for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==c){
                    if(makec(grid,i+1,j,n,c)||makec(grid,i,j+1,n,c)||makec(grid,i-1,j,n,c)||makec(grid,i,j-1,n,c)) return c-2;
                }
            }
            
        }
        }
        return -1;
    }