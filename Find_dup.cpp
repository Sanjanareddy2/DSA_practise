//https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int freq(int ele , vector<int>& nums){
        int n = nums.size(),count =0;
        for(int i = 0;i<n;i++){
            if(nums[i]<= ele) count++;
        }
        return count;
    }
    int findDuplicate(vector<int>& nums) {
        int l = 0,h = nums.size()-1,mid,sol=0;
        while(l<=h){
            mid = (l+h)/2;
            if(freq(mid,nums)>mid){
                sol=mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return sol;
    }
    
};