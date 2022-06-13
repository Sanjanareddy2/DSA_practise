//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/

//this is for a connected graph

 void dfs(vector<int> adj[],vector<int>&sol,vector<bool>&visited,int x){
        visited[x]=true;
        sol.push_back(x);
        for(auto itr : adj[x]){
            if(!visited[itr])
                dfs(adj,sol,visited,itr);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> sol;
        vector<bool> visited(V,false);
        dfs(adj,sol,visited,0);
        return sol;
    }
