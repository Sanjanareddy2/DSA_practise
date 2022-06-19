//https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1#

long long help(int n,int i, int j,vector<vector<vector<long long>>>& dp){
	    if(i<0 || i>=3 || j<0 || j>=4 ||(j==3 && i!=1)) return 0;
	    if(n==1){
	        dp[i][j][n]=1;
	         return 1;
	    }
	    
	    if(dp[i][j][n]>0) return dp[i][j][n];
	    dp[i][j][n]=help(n-1,i+1,j,dp)+
	            help(n-1,i-1,j,dp)+
	            help(n-1,i,j+1,dp)+
	            help(n-1,i,j-1,dp)+help(n-1,i,j,dp);
	   return dp[i][j][n];
	}
	long long getCount(int n)
	{
		// Your code goes here
		vector<vector<vector<long long>>> dp(3,vector<vector<long long>>(4,vector<long long>(27,0)));
		long long sol = 0;
		for(int i=0;i<3;i++){
		    for(int j=0;j<4;j++){
		        sol += help(n,i,j,dp);
		    }
		}
		return sol;
	}