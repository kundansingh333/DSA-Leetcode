class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        // for(auto x: nums){
        //     mp[x]=0;
        // }
        int i=0,j=0;
        int n=nums.size();
        int maxi=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;

        }

        return maxi;
    }
};