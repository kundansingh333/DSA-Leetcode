class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        // sort(grid.begin(),grid.end());
        vector<vector<int>>ans(m-k+1,vector<int>(n-k+1));
        for(int i=0; i<=m-k ;i++){
            for(int j=0; j<=n-k; j++){
                set<int>val;
                for(int l=i; l<=i+k-1; l++){
                    for(int m=j; m<=j+k-1; m++){
                        val.insert(grid[l][m]);
                    }
                }
                if(val.size()==1){
                    ans[i][j]=0;
                    continue;
                }
                int minAbsDiff=INT_MAX;
                auto prev=val.begin();
                auto curr=next(prev);
                while(curr!=val.end()){
                    minAbsDiff=min(minAbsDiff,abs(*prev-*curr));
                    prev=curr;
                    curr++;
                }
                ans[i][j]=minAbsDiff;
            }


        }
        return ans;
    }
};