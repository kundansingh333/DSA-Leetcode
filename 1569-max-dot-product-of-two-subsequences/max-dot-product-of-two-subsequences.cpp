class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>>dp(n1,vector<int>(n2));

        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                int current_product=nums1[i]*nums2[j];
                if(i>0 && j>0){
                    current_product+=max(0,dp[i-1][j-1]);
                }
                dp[i][j]=current_product;
                if(i>0) dp[i][j]=max(dp[i][j],dp[i-1][j]);
                if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }

        }
        return dp[n1-1][n2-1];

    }
};