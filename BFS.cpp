//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> sol;
        vector<bool> visited(V,false);
        queue<int> q;
        q.push(0);
        sol.push_back(0);
        visited[0]=true;
        while(!(q.empty())){
            int x = q.front();
            q.pop();
            for(auto itr : adj[x] ){
                if(visited[itr]==false){
                    q.push(itr);
                    sol.push_back(itr);
                    visited[itr]=true;
                }
            }
        }
        return sol;
    }