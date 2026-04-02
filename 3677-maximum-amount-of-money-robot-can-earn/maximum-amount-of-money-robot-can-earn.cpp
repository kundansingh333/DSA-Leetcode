class Solution {
public:
    int maxi=INT_MIN;
    
    
    int fun(vector<vector<int>>&coins,int i, int j,int m,int n,int count,vector<vector<vector<int>>>&dp){
        if(i>=m || j>=n){
            return -1e9;
        }

        if(dp[i][j][count]!=-1e9){
            return dp[i][j][count];
        }
        int current_coins=coins[i][j];

        if(i==m-1 && j==n-1){
            if(current_coins<0 && count<2){
                return dp[i][j][count]=0;
            }
            return dp[i][j][count]=current_coins;
        }
        //netural path if applicable
        int take_neutral=-1e9;
        if(count<2 && current_coins<0){
            take_neutral=0+max(fun(coins,i+1,j,m,n,count+1,dp),fun(coins,i,j+1,m,n,count+1,dp));
        }
        //normal path
        int take_normal=current_coins+max(fun(coins,i+1,j,m,n,count,dp),fun(coins,i,j+1,m,n,count,dp));
        return dp[i][j][count]= max(take_neutral,take_normal);
        
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,-1e9)));
        return fun(coins,0,0,m,n,0,dp);
    }
};