//https://leetcode.com/problems/game-of-life/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(),n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j] *= 100;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0 && board[i-1][j]/100==1){
                    board[i][j]+=10;
                }
                if(i<m-1 && board[i+1][j]/100==1){
                    board[i][j]+=10;
                }
                if(j>0 && board[i][j-1]/100==1){
                    board[i][j]+=10;
                }
                if(j<n-1 && board[i][j+1]/100==1){
                    board[i][j]+=10;
                }
                if(i>0 && j>0 && board[i-1][j-1]/100==1) board[i][j]+=10;
                if(i>0 && j<n-1 && board[i-1][j+1]/100==1) board[i][j]+=10;
                if(i<m-1 && j>0 && board[i+1][j-1]/100==1) board[i][j]+=10;
                if(i<m-1 && j<n-1 && board[i+1][j+1]/100==1) board[i][j]+=10;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]/100==1){
                    if((board[i][j]/10)%10 < 2) {}
                    else if ((board[i][j]/10)%10 == 2 || (board[i][j]/10)%10 == 3) board[i][j]++;
                    else {}
                }
                else{
                    if((board[i][j]/10)%10 == 3) board[i][j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j] = (board[i][j]%100)%10;
            }
        }
        
        
    }
};