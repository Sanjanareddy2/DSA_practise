//https://leetcode.com/problems/subsets-ii/

void help(vector<int> &nums ,int i,int n,int k,vector<int> &s,vector<vector<int>> &sol,map<vector<int>,int>& mp){
        
            mp[s]++;
            if(mp[s]==1)sol.push_back(s);
            
        if(i>=n) return;
        s.push_back(nums[i]);
        help(nums,i+1,n,k-1,s,sol,mp);
        s.pop_back();
        help(nums,i+1,n,k,s,sol,mp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> sol;
       map<vector<int>,int> mp;
        int n = nums.size();
        
             vector<int> s;
            help(nums,0,n,0,s,sol,mp);
        
        return sol;
    }