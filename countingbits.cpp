//https://leetcode.com/problems/counting-bits/

vector<int> countBits(int n) {
        vector<int> sol(n+1,-1);
        sol[0]=0;
        if(n==0) return sol;
        sol[1]=1;
        if(n==1) return sol;
        sol[2]=1;
        if(n==2) return sol;
        for(int i=3;i<=n;i++){
            sol[i] = sol[i/2]+(i%2);
        }
        return sol;
    }