//https://leetcode.com/problems/integer-to-roman/
class Solution {
public:
    string intToRoman(int num) {
        map<int , string> mp1,mp2,mp3,mp4;
        mp1[1] = "I" ; mp1[2] = "II"; mp1[3] = "III"; mp1[4] = "IV"; mp1[5] = "V"; mp1[6] = "VI"; mp1[7] = "VII" ; mp1[8] = "VIII"; mp1[9] = "IX";
        mp2[1] = "X"; mp2[2] = "XX"; mp2[3] = "XXX"; mp2[4] = "XL"; mp2[5] = "L"; mp2[6] = "LX"; mp2[7] = "LXX"; mp2[8] = "LXXX"; mp2[9] = "XC";
        mp3[1] = "C"; mp3[2] = "CC"; mp3[3] = "CCC"; mp3[4] = "CD"; mp3[5] = "D" ; mp3[6] = "DC"; mp3[7] = "DCC"; mp3[8] = "DCCC" ; mp3[9] = "CM" ;
        mp4[1] = "M"; mp4[2] = "MM"; mp4[3] = "MMM";
        
        string sol = "";
        if((num/1000)%10 !=0) sol += mp4[(num/1000)%10];
        if((num/100)%10 != 0) sol += mp3[(num/100)%10];
        if((num/10)%10 != 0) sol += mp2[(num/10)%10] ;
        if(num%10 != 0 ) sol += mp1[num%10];
        return sol;
    }
};
