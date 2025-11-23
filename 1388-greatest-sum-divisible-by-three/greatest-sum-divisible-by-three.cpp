class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int PLACEHOLDER=-1000000000;
        vector<int> dp(3,PLACEHOLDER);
        dp[0]=0;

        for(int num : nums){
            vector<int> next_dp=dp;
            for(int i=0; i<3; i++){


                if(dp[i]==PLACEHOLDER){
                    continue;
                }
                int new_sum=dp[i]+num;
                int new_remain=new_sum%3;
                next_dp[new_remain]=max(new_sum,next_dp[new_remain]);
            }
            dp=next_dp;
        }
        return dp[0];

    }
};