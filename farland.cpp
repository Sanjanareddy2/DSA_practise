//https://leetcode.com/problems/as-far-from-land-as-possible/

 int s =1;
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q,q1;
        int m = grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i-1,j});
                    q.push({i+1,j});
                    q.push({i,j-1});
                    q.push({i,j+1});
                }
            }
        }
        while(!(q.empty())){
            s++;
            while(!(q.empty())){
                int i = q.front().first,j=q.front().second;
                q.pop();
                if(i>=0&&j>=0&&i<m&&j<n&&grid[i][j]==0){
                    grid[i][j]=s;
                    q1.push({i-1,j});
                    q1.push({i+1,j});
                    q1.push({i,j-1});
                    q1.push({i,j+1});
                }
            }
            swap(q,q1);
        }
        return (s==2)? -1: s-2;
    }