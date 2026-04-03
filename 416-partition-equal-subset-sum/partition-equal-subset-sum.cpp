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
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2!=0){
            return false;
        }else{
            return fun(nums,sum/2,n);
        }
    }
};