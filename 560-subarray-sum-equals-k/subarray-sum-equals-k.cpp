class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;


        int current_sum=0;
        int total_subarrays=0;

        for(auto num:nums){
            current_sum+=num;
            int target=current_sum-k;
            if(mp.count(target)){
                total_subarrays+=mp[target];
            }
            mp[current_sum]++;
        }
        return total_subarrays;
    }
};