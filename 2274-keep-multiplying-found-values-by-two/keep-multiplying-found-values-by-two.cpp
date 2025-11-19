class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int newOriginal=0;
        while(newOriginal!=original){
            newOriginal=original;
            for(int i=0; i<nums.size(); ++i){
            if(nums[i]==original){
                original=2*original;
                break;
            }
        }
        
        }
        return original;
        
    }
};