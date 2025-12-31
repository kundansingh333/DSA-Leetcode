class Solution {
public:

    bool canCross(int n, int m, int day, vector<vector<int>>&cells){
        //4 directions
        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};

        //visited 
        vector<vector<int>> grid(n,vector<int>(m,0));

        //fill the water till day
        for(int i=0; i<day; i++){
            grid[cells[i][0]-1][cells[i][1]-1]=1;
        }

        //setup for the bfs
        queue<pair<int,int>>q;
        for(int c=0; c<m; c++){
            if(grid[0][c]==0){
                q.push({0,c});
                grid[0][c]=1;
            }
        }
        //run bfs

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            if(r==n-1) return true;
            //checking neighbour
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                    grid[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return false;



    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left=1;
        int right=cells.size();
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canCross(row,col,mid,cells)){
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
        
    }
};