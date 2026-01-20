class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector <int> result(nums.size(),-1);
        for(int i=0; i<nums.size(); i++){
            for(int j=1;j<=nums[i];j++){
                if(nums[i]==(j | (j+1))){
                    result[i]=j;
                    break;
                }
            }
        }
        return result;
    }
};