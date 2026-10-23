class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int index=-1;
        
        for(int i=0; i<n; i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                index=i;
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i]*2>maxi && nums[i]!=maxi){
                return -1;
            }
        }
        return index;
    }
};