//https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
       int maxa = -1,i=0,j=height.size()-1;
       while(i<=j){
           maxa = max(maxa, (j-i)*(min(height[i],height[j])));
           if(height[i]>height[j]) j--;
           else i++;
       }
        return maxa;
    }
};
//first you should get idea of min of both heights is used in this array.