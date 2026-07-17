class Solution {
public:
    vector<vector<string>>ans;
    bool check(vector<vector<int>>&board,int colIdx,int rowIdx,int n){
        //left side check
        for(int col=0; col<colIdx; col++){
            if(board[rowIdx][col]==1){
                return false;
            }
        }
        //diagonally left-up
        int i=rowIdx, j=colIdx;
        while(i>=0 and j>=0){
            if(board[i][j]==1){
                return false;
            }
            i-=1;
            j-=1;
        }
        //diagonally left-down
        i=rowIdx,j=colIdx;
        while(i<n and j>=0){
            if(board[i][j]==1){
                return false;
            }
            i+=1;
            j-=1;
        }
        return true;
    }
    void helper(vector<vector<int>>&board,vector<string>&temp,int n,int colIdx){
        if(n==colIdx){
            ans.push_back(temp);
            return;
        }
        for(int rowIdx=0; rowIdx<n; rowIdx++){
            if(check(board,colIdx,rowIdx,n)){
                string sol(n,'.');
                sol[rowIdx]='Q';
                temp.push_back(sol);
                board[rowIdx][colIdx]=1;

                helper(board,temp,n,colIdx+1);

                temp.pop_back();
                board[rowIdx][colIdx]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<string>temp;
        helper(board,temp,n,0);
        return ans;
    }
};