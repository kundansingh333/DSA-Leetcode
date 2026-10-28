class Solution {
public:
    int memo[1005][1024];
    int m,n;
    int solve(int r,int c, int current_xor,vector<vector<int>>&grid){
        current_xor^=grid[r][c];
        if(r==m-1 && c==n-1){
            return current_xor;
        }
        int cell_index=r*n+c;
        if(memo[cell_index][current_xor]!=-1){
            return memo[cell_index][current_xor];
        }
        int min_val=INT_MAX;
        if(r+1<m){
            min_val=min(min_val,solve(r+1,c,current_xor,grid));
        }
        if(c+1<n){
            min_val=min(min_val,solve(r,c+1,current_xor,grid));
        }
        return memo[cell_index][current_xor]= min_val;
    }
    int minCost(vector<vector<int>>& grid) {
        
        m=grid.size();
        n=grid[0].size();
        memset(memo,-1,sizeof(memo));

        return solve(0,0,0,grid);
    }
};