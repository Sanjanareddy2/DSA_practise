//https://leetcode.com/problems/reverse-words-in-a-string/
class Solution {
public:
    string reverseWords(string s) {
       stringstream ss(s);
        stack<string> stk;
        string str = "";
        while(ss >> str){
            stk.push(str);
        }
        string sol = "";
        while(!(stk.empty())){
            sol = sol + " " + stk.top();
            stk.pop();
        }
        return sol.substr(1,sol.size()-1);
    }
};