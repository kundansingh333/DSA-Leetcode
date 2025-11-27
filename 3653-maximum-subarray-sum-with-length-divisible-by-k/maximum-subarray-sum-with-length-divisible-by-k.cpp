class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long currentSum=0;
        long long maxi=LLONG_MIN;


        vector<long long> minPrefix(k,LLONG_MAX);
        minPrefix[0]=0;
        for(int i=0; i<nums.size();i++){
            currentSum+=nums[i];

            int currentLength=i+1;
            int remainder=currentLength%k;

            if(minPrefix[remainder]!=LLONG_MAX){
                long long validSubarraySum=currentSum-minPrefix[remainder];
                maxi=max(maxi,validSubarraySum);
            }
            minPrefix[remainder]=min(minPrefix[remainder],currentSum);
        }
        return maxi==LLONG_MIN?0:maxi;

        
        
    }
};