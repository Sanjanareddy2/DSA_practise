//https://leetcode.com/problems/time-needed-to-inform-all-employees/

    vector<vector<int>> adj;
    int dfs(int m , vector<int>& info ){
        int time = 0;
        for(auto itr : adj[m])
            time = max(time,dfs(itr,info));
        return info[m]+time;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.resize(n);
        for(int i=0;i<n;i++){
           if(manager[i]!=-1) adj[manager[i]].push_back(i);
        }
        return dfs(headID,informTime);
    }        