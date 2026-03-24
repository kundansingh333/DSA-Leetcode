class Solution {
public:
    using ll=long long;
    
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mod=12345;

        vector<vector<int>>ans(n,vector<int>(m,1));
        //prefix calculation;
        ll prefix=1;
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                ans[i][j]=prefix;
                prefix=(prefix*grid[i][j])%mod;
            }
        }

        //suffix calculation
        ll suffix=1;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                ans[i][j]=(ans[i][j]*suffix)%mod;
                suffix=(grid[i][j]*suffix)%mod;
            }
        }
        return ans;
    }
};