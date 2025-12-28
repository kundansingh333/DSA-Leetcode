class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0; i<=n-1; i++){
            for(int j=0; j<=m-1;j++){
                if(grid[i][j]<0){
                    int total=m-j;
                    count+=total;
                    break;
                }
            }
        }
        return count;
    }
};