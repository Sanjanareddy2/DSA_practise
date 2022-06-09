//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(),cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])cnt++;
            else nums[i-cnt]=nums[i];
        }
        return n-cnt;
    }
};
//nums.erase(unique(nums.begin(),nums.end()),nums.end());