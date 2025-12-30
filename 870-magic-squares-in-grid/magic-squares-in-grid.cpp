class Solution {
public:

    bool isMagic(vector<vector<int>> grid,int rows,int cols){
        vector<int> count(16,0);
        for(int i=rows; i<rows+3; i++){
            for(int j=cols; j<cols+3; j++){
                int val=grid[i][j];
                if(val<1 || val>9) return false;
                if(count[val]>0) return false;
                count[val]++;
            }

        } 
        //rows sum
        if(grid[rows][cols]+grid[rows][cols+1]+grid[rows][cols+2]!=15) return false;
        if(grid[rows+1][cols]+grid[rows+1][cols+1]+grid[rows+1][cols+2] !=15) return false;
        if(grid[rows+2][cols]+grid[rows+2][cols+1]+grid[rows+2][cols+2] !=15) return false;
        // columns sum

        if(grid[rows][cols]+grid[rows+1][cols]+grid[rows+2][cols] !=15) return false;
        if(grid[rows][cols+1]+grid[rows+1][cols+1]+grid[rows+2][cols+1] !=15) return false;
        if(grid[rows][cols+2]+grid[rows+1][cols+2]+grid[rows+2][cols+2]!=15) return false;

        //diagonal

        if(grid[rows][cols]+grid[rows+1][cols+1]+grid[rows+2][cols+2]!=15) return false;
        if(grid[rows][cols+2]+grid[rows+1][cols+1]+grid[rows+2][cols] !=15) return false;

        return true;

    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;

        if(rows<3 || cols<3) return 0;
        for(int i=0; i<=rows-3; i++){
            for(int j=0; j<=cols-3; j++){
                if(isMagic(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};