//https://leetcode.com/problems/number-of-operations-to-make-network-connected/

void dfs(vector<vector<int>> &adj,vector<bool>&visited,int i, int n){
        visited[i]=true;
        for(auto itr : adj[i])
            if(visited[itr]==false)
                dfs(adj,visited,itr,n);
    }
    int makeConnected(int n, vector<vector<int>>& conn) {
        int m = conn.size();
        if(m< n-1) return -1;
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++){
            adj[conn[i][0]].push_back(conn[i][1]);
            adj[conn[i][1]].push_back(conn[i][0]);
        }
        int sol = 0;
        
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                sol++;
                dfs(adj,visited,i,n);
            }
        }
            
        return sol-1;
    }