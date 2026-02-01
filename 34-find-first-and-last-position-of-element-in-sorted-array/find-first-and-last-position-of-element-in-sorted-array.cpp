class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=-1;
        int end=-1;
       for(int i=0; i<nums.size(); i++){
            if(nums[i]==target && start == -1){
                start=i;
            }
            if(nums[i]==target){
                end=i;
            }
        }
        return {start,end};
    }
};