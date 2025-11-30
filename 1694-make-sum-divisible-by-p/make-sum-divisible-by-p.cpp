class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum=0;
        long currentPrefixSum=0;
        for(int it:nums)totalSum+=it;
        int rem=totalSum%p;
        if(rem==0){
            return 0;
        }
        int minLen=nums.size();
        unordered_map<int,int> mp ;//( prefixSum%p)->key
        mp[0]=-1;
        for(int i=0; i<nums.size(); i++){
            currentPrefixSum+=nums[i];
            int currentMod=currentPrefixSum%p;
            int targetMod=(currentMod-rem+p)%p;
            if(mp.find(targetMod)!=mp.end()){
                minLen=min(minLen,i-mp[targetMod]);
            }
            mp[currentMod]=i;
        }

        return minLen==nums.size()?-1:minLen;

        
    }
};