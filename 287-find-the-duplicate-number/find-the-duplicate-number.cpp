class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(auto it:nums){
        //     mp[it]++;
        // }
        // for(auto [key,val]:mp){
        //     if(val>1){
        //         return key;
        //     }
        // }
        // return 0;

        int slow=0,fast=0;
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast){
                break;
            }
        }
        int slow2=0;
        while(true){
            slow=nums[slow];
            slow2=nums[slow2];
            if(slow==slow2){
                return slow;
            }
        }
    }
};