//https://leetcode.com/problems/decode-ways/

int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]= s[0]=='0'? 0:1;
        for(int i=2;i<=n;i++){
            int x = stoi(s.substr(i-1,1));
            int y = stoi(s.substr(i-2,2));
            //cout << x <<" "<<y;
            if(x>=1 && x<=9)
                dp[i]+=dp[i-1];
            if(y>=10 && y<=26)
                dp[i]+=dp[i-2];
        }
        return dp[n];
    }