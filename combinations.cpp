//https://leetcode.com/problems/combinations/


void help(int n, int k,int i,vector<int> &s,vector<vector<int>> &sol){
        if(k==0){
            sol.push_back(s);
            return;
        }
        if(i>n) return;
        s.push_back(i);
        help(n,k-1,i+1,s,sol);
        s.pop_back();
        help(n,k,i+1,s,sol);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> sol;
        vector<int> s;
        help(n,k,1,s,sol);
        return sol;
    }