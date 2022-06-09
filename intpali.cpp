//https://leetcode.com/problems/palindrome-number/
class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        if(x<0) return false;
        else {
            long int y=0;
            while(x!=0){
                y=y*10+(x%10);
                x/=10;
            }
            if(temp==y) return true;
            else return false;
        }
        
    }
};