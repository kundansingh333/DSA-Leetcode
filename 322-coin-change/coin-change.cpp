class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>t(n+1 ,vector<int>(amount+1));
        //initialization
        for(int i=0; i<t.size(); i++){
            for(int j=0; j<t[0].size(); j++){
                if(i==0){
                    t[i][j]=INT_MAX-1;
                }
                if(i!=0 && j==0){
                    t[i][j]=0;
                }
            }
        }
        //for second row 
        // for(int i=1; i< amount+1; i++){
        //     if(i % coins[i]==0){
        //         t[1][i]=1;
        //     }else{
        //         t[1][i]=INT_MAX-1;
        //     }
        // }



        for(int i=1; i<t.size(); i++){
            for(int j=1; j<t[0].size(); j++){
                if(coins[i-1]<=j){
                    t[i][j]=min(1+t[i][j-coins[i-1]] ,t[i-1][j]);
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        if(t[n][amount]==INT_MAX-1){
            return -1;
        }
        return t[n][amount];

    }
};