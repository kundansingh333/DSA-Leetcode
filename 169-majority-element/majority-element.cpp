class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int should=n/2;
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(int i=0; i<n; i++){
            if(mp[nums[i]]>should){
                return nums[i];
            }
        }
        return 0;
    }
};