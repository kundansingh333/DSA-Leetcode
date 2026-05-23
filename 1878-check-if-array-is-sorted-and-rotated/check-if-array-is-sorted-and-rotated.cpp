class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int drop_count=0;
        for(int i=0; i<n; i++){
            if(nums[i]>nums[(i+1)%n]){
                drop_count+=1;
            }
            if(drop_count>1){
                return false;
            }
        }
        return true;
    }
};