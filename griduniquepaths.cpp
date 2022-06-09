int helper(int A, int B, int i , int j){
    if(A==i || B==j) return 1;
    return helper(A,B,i+1,j)+helper(A,B,i,j+1);
}
int Solution::uniquePaths(int A, int B) {
    return helper(A-1,B-1,0,0);
}
