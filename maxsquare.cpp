//https://leetcode.com/problems/maximal-square/

 int maximalSquare(vector<vector<char>>& ma) {
        int n = ma.size(),m=ma[0].size(),res=0;
        vector<vector<int>> matrix(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ma[i][j]=='0') matrix[i][j]=0;
                else matrix[i][j]=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] && i && j){
                    matrix[i][j] += min(matrix[i-1][j-1] , min(matrix[i-1][j],matrix[i][j-1]));
                }
                res < matrix[i][j] ? res = matrix[i][j] : res=res;
                //cout << matrix[i][j] <<" "<<res <<'\n';
            }
        }
        return res*res;
    }