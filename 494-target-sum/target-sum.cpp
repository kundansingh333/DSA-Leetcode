class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if((sum+target)%2!=0 || abs(target)>sum){
            return 0;
        }
        int s=(sum+target)/2;
        vector<vector<int>> t(n+1,vector<int>(s+1,0));
        t[0][0]=1;

        for(int i=1; i<t.size(); i++){
            for(int j=0; j<t[0].size(); j++){
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][s];
    }
};