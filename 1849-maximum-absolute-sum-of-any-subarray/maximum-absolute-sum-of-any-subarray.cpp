class Solution {
public:
    int maxi(vector<int> nums){
        int bestEnding=nums[0];
        int res=nums[0];
        for(int i=1; i<nums.size(); i++){
            int v1=nums[i];
            int v2=bestEnding+nums[i];
            bestEnding=max(v1,v2);
            res=max(res,bestEnding);

        }
        return res;
    }
    int mini(vector<int> nums){
        int bestEnding=nums[0];
        int res=nums[0];
        for(int i=1; i<nums.size(); i++){
            int v1=nums[i];
            int v2=bestEnding+nums[i];
            bestEnding=min(v1,v2);
            res=min(res,bestEnding);

        }
        return res;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int max_element=abs(maxi(nums));
        int min_element=abs(mini(nums));
        int result=max(max_element,min_element);
        return result;
    }
};