class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>result;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=val){
                count++;
                result.push_back(nums[i]);
            }
        }
        nums=result;
        return count;
    }
};