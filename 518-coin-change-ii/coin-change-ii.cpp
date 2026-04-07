class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned int>>t(n+1,vector<unsigned int>(amount+1,0));

        t[0][0]=1;
        for(int i=1; i<t.size(); i++){
            for(int j=0; j<t[0].size(); j++){
                if(coins[i-1]<=j){
                    t[i][j]=t[i][j-coins[i-1]]+t[i-1][j];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][amount];
    }
};