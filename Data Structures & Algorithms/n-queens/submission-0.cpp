class Solution {
public:
    bool issafe(vector<string> &board,int row, int col, int n){
        //vertical
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q') return false;
        }
        //horizontal
        for(int i=0;i<n;i++){
            if(board[row][i]=='Q') return false;
        }
        //left diag
        for(int i=row, j=col;(i>=0 && j>=0);i--,j--){
            if(board[i][j]=='Q') return false;
        }
        //right diag
        for(int i=row, j=col;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void nqueens(int n,vector<string> &board, int row, vector<vector<string>> &ans){
        if(n==row){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){//i is the column
            if(issafe(board,row,i,n)){
                board[row][i]='Q';
                nqueens(n,board,row+1,ans);
                board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        nqueens(n,board,0,ans);
        return ans;
    }
};
