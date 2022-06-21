//https://leetcode.com/problems/permutations-ii/

void help(vector<int>& nums,vector<int>&s,vector<vector<int>>&sol, int n,map<int,int>&mp,map<vector<int> , int>&mp1){
        if(s.size()==n){
            mp1[s]++;
            if(mp1[s]==1) sol.push_back(s);
            return;
        }
        for(int j=0;j<n;j++){
            if(mp[j]==0){
                s.push_back(nums[j]);
                mp[j]++;
                help(nums,s,sol,n,mp,mp1);
                mp[j]--;
                s.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>s;
        vector<vector<int>>sol;
        int n = nums.size();
        map<int,int>mp;
        map<vector<int> , int>mp1;
        help(nums,s,sol,n,mp,mp1);
        return sol;
    }