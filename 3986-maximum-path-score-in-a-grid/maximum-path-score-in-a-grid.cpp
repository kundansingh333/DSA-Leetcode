class Solution {
public:
    int m, n;
    int fun(vector<vector<int>>&grid ,int i, int j,int k, int cost,vector<vector<vector<int>>>&t){
        //base case
        if(i>=m || j>=n){
            return INT_MIN;
        }
        int newCost=cost+(grid[i][j]>0?1:0);
        if(newCost>k){
            return INT_MIN;
        }
        if(i==m-1 && j==n-1 ){
            return grid[i][j];
        }
        if(t[i][j][newCost]!=-1){
            return t[i][j][newCost];
        }
        int right=fun(grid,i,j+1,k,newCost,t);
        int down = fun(grid,i+1,j,k,newCost,t);
        if(right==INT_MIN && down==INT_MIN){
            return t[i][j][newCost] = INT_MIN;
        }

        return t[i][j][newCost] = max(right,down)+grid[i][j];
        
        
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {

        m=grid.size();
        n= grid[0].size();
        vector<vector<vector<int>>>t(m+1,vector<vector<int>>(n+1,vector<int>(1001,-1)));
        int ans=fun(grid,0,0,k,0,t);
        return ans==INT_MIN?-1:ans;

        

    }
};