//https://leetcode.com/problems/longest-increasing-subsequence/

int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),maxsol = 1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1)
                    dp[i] = dp[j]+1;
                if(maxsol<dp[i]) maxsol = dp[i];
            }
        }
        return maxsol;
        
    }

//better solution using binary search

int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sol;
        for(int i=0;i<n;i++){
            if(sol.size()==0 || sol[sol.size()-1]<nums[i])
                sol.push_back(nums[i]);
            if(sol[sol.size()-1]>nums[i]){
                auto it = lower_bound(sol.begin(),sol.end(),nums[i]);
                *it = nums[i];
            }
        }
        return sol.size();
    }