//https://leetcode.com/problems/evaluate-division/

 vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string , vector<string>> adj;
        map<pair<string,string> , double> mp;
        int n = equations.size(),m = queries.size();
        for(int i=0;i<n;i++){
            adj[equations[i][0]].push_back(equations[i][1]);
            adj[equations[i][1]].push_back(equations[i][0]);
            mp[{equations[i][0],equations[i][1]}] = values[i];
            mp[{equations[i][1],equations[i][0]}] = 1/values[i];
        }
        vector<double> sol;
        for(int j = 0;j<m;j++){
            string a = queries[j][0],b=queries[j][1];
            map<string , int> visited;
            queue<pair<string,double>> q;
            q.push({a,1.0});
            bool flg = false;
            if(adj[a].size()==0 || adj[b].size()==0){
                sol.push_back(-1.0);
                continue;
            }
            while(!(q.empty())){
                pair<string,double> str = q.front();
                q.pop();
                visited[str.first]++;
                if(str.first==b){
                    flg = true;
                    sol.push_back(str.second);
                    break;
                }
                for(auto itr : adj[str.first]){
                    if(visited[itr]==0)
                        q.push({itr,str.second*mp[{str.first,itr}]});
                }
            }
            if(flg == false) sol.push_back(-1.0);
            
        }
        return sol;
    }