//https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(k,0);
        int pfx=0;
        for(int i=0;i<n;i++){
            pfx =( pfx + nums[i]%k +k)%k;
            freq[pfx]++;
        }
        int sol=(freq[0]*(freq[0]+1))/2;
        for(int i=1;i<k;i++){
            sol+= (freq[i]*(freq[i]-1))/2;
        }
        return sol;
    }
};