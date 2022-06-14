//https://leetcode.com/problems/find-eventual-safe-states/

/*Thinking about this property more, a node is eventually safe if all it's outgoing edges are to nodes that are eventually safe.
We'll keep track of graph, a way to know for some node i, what the outgoing edges (i, j) are. We'll also keep track of rgraph,
 a way to know for some node j, what the incoming edges (i, j) are.

Now for every node j which was declared eventually safe, we'll process them in a queue. We'll look at all parents i = rgraph[j] 
and remove the edge (i, j) from the graph (from graph). If this causes the graph to have no outgoing edges graph[i], 
then we'll declare it eventually safe and add it to our queue.

Also, we'll keep track of everything we ever added to the queue, so we can read off the answer in sorted order later.*/

vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        queue<int> q;
        map<int,int> sol;
        vector<vector<int>> rg(n);
        
        for(int i=0;i<n;i++){
            int x = g[i].size();
            
            if(x==0) {
                q.push(i);
                sol[i]++;
            }
            for(int j=0;j<x;j++){
                rg[g[i][j]].push_back(i);
            }
        }
        vector<bool> visit(n,false);
        while(!(q.empty())){
            int x = q.front();
            q.pop();
            visit[x]=true;
            for(auto itr : rg[x]){
                if(visit[itr]==false){
                    bool safe = true;
                vector<int> t = g[itr];
                for(int i=0;i<t.size();i++){
                    if(sol[t[i]]==0){
                        safe = false;
                        break;
                    }
                }
                if(safe){
                    sol[itr]++;
                    q.push(itr);
                }
                }
            }
        }
        vector<int> s;
        for(auto itr : sol){
            if(itr.second>0) s.push_back(itr.first);
        }
        return s;
    }