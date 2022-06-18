//https://leetcode.com/problems/unique-paths/

int dp[102][102] = {-1};
    int help(int i, int j, int m,int n){
        if(i<0||i>=m||j<0||j>=n) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]>0) return dp[i][j];
        dp[i][j]=help(i-1,j,m,n)+help(i,j-1,m,n);
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        return help(m-1,n-1,m,n);
    }