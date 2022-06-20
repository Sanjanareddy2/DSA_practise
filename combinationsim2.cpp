//https://leetcode.com/problems/combination-sum-ii/

void help(vector<int>& candidates, int target,vector<int> &s,vector<vector<int>> &sol,int i,map<vector<int>,int> &mp,int n){
        
        if(target < 0) return;
        
        if(target == 0){
            
           sol.push_back(s);
            return;            
        }
        if(i>=n) return;
        int num = candidates[i];
        s.push_back(candidates[i]);
        //cout << candidates[i] <<"inc\n";
        if(target-candidates[i] >= 0)help(candidates,target-candidates[i],s,sol,i+1,mp,n);
        s.pop_back();
        //cout << candidates[i] <<"del\n";
        while(i<n-1 && candidates[i+1] == num ) i++;
        if(target >= 0)help(candidates,target,s,sol,i+1,mp,n);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        map<vector<int>,int> mp;
        vector<vector<int>> sol ;
        vector<int> s;
        int n = candidates.size();
        help(candidates,target,s,sol,0,mp,n);
        return sol;
    }