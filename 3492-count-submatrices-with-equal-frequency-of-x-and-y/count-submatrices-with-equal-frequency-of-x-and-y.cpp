class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>cum_x(m,vector<int>(n,0));
        vector<vector<int>>cum_y(m,vector<int>(n,0));
        
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cum_x[i][j]=(grid[i][j]=='X');
                cum_y[i][j]=(grid[i][j]=='Y');

                if(i>0){
                    cum_x[i][j]+=cum_x[i-1][j];
                cum_y[i][j]+=cum_y[i-1][j];
                }
                if(j>0){
                    cum_x[i][j]+=cum_x[i][j-1];
                    cum_y[i][j]+=cum_y[i][j-1];
                }
                if(i>0 && j>0){
                    cum_x[i][j]-=cum_x[i-1][j-1];
                    cum_y[i][j]-=cum_y[i-1][j-1];
                }

                if(cum_x[i][j]==cum_y[i][j] && cum_x[i][j]>0){
                    count++;
                }
                
            }
            
        }
        return count;
    }
};