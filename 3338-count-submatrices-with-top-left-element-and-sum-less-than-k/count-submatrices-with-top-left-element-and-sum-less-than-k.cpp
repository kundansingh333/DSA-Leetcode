class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int valid_count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int top=(i>0)?grid[i-1][j]:0;
                int left=(j>0)?grid[i][j-1]:0;
                int top_left=(i>0 && j>0)?grid[i-1][j-1]:0;
                grid[i][j]+=top+left-top_left;

                if(grid[i][j] <=k){
                    valid_count++;
                }

            }
        }
        return valid_count;
    }
};