//https://leetcode.com/problems/count-square-submatrices-with-all-ones/

int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size(),res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] && i && j){
                    matrix[i][j] += min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i][j-1]));
                
                }res+= matrix[i][j];
            }
        }
        return res;
    }