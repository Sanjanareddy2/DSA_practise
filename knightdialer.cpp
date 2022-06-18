//https://leetcode.com/problems/knight-dialer/

long int m[3][4][5002];
    long paths( int i , int j , int n ){
        if(i>=3 || i<0 || j>=4 || j<0 ||(j==3 && i!=1)) return 0;
        if(n==1){
            m[i][j][n]=1;
            return 1;
        }
        if(m[i][j][n]>0) return m[i][j][n];
        m[i][j][n] = paths(i-2,j-1,n-1)+
                    paths(i-2,j+1,n-1)+
                    paths(i-1,j+2,n-1)+
                    paths(i+1,j+2,n-1)+
                    paths(i+2,j+1,n-1)+
                    paths(i+2,j-1,n-1)+
                    paths(i+1,j-2,n-1)+
                    paths(i-1,j-2,n-1);
        m[i][j][n] = m[i][j][n]% 1000000007;
        return m[i][j][n];
        
    }
    int knightDialer(int n) {
        
        long int s =0;
        for(int i=0;i<3;i++){
            for(int j=0;j<4;j++){
                s = (s+paths(i,j,n))%1000000007;
            }
        }
        return (int)s;
    }