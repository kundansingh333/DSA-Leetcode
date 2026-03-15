class Solution {
public:
    int middle_max(vector<int> nums){
        int bestEnding=nums[0];
        int res=nums[0];
        for(int i=1; i<nums.size(); i++){
            int v1=nums[i];
            int v2=nums[i]+bestEnding;
            bestEnding=max(v1,v2);
            res=max(res,bestEnding);
        }
        return res;
    }
    int both_end_max(vector<int> nums){

        int bestEnding=nums[0];
        int res=nums[0];
        for(int i=1; i<nums.size(); i++){
            int v1=nums[i];
            int v2=nums[i]+bestEnding;
            bestEnding=min(v1,v2);
            res=min(res,bestEnding);
        }
        int total=accumulate(nums.begin(),nums.end(),0);
        return total-res;

    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int first=middle_max(nums);
        if(first<0){
            return first;
        }
        int second=both_end_max(nums);
        int result=max(first,second);
        return result;
    }
};