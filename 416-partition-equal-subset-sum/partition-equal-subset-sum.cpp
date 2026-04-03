class Solution {
public:
    vector<vector<int>>t=vector<vector<int>>(202,vector<int>(10002,-1));
    bool fun(vector<int>&nums,int sum, int n){
        if(n==0){
            return 0;
        }
        if(sum==0){
            return 1;
        }
        if(t[n][sum]!=-1){
            return t[n][sum];
        }
        if(nums[n-1]<=sum){
            return t[n][sum] = fun(nums,sum-nums[n-1],n-1) || fun(nums,sum,n-1);
        }else{
            return t[n][sum] = fun(nums,sum,n-1);
        }
    }
    bool canPartition(vector<int>& nums) {
        // int n=nums.size();
        // int sum=0;
        // for(auto it:nums){
        //     sum+=it;
        // }
        // if(sum%2!=0){
        //     return false;
        // }else{
        //     return fun(nums,sum/2,n);
        // }

        //top-down approach
        int n=nums.size();
        int sum=0;
        for(auto it: nums){
            sum+=it;
        }
        if(sum%2!=0){
            return 0;
        }
        int s=sum/2;
        vector<vector<int>>t(n+1,vector<int>(s+1));
        //initialization
        for(int i=0; i<n+1; i++){
            for(int j=0; j<s+1; j++){
                if(i==0){
                    t[i][j]=0;
                }
                if(j==0){
                    t[i][j]=1;
                }
            }
        }
        //choice diagram
        for(int i=1; i<t.size(); i++){
            for(int j=1; j<t[0].size(); j++){
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j-nums[i-1]] || t[i-1][j];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][s];
    }
};