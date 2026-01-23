class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for(int i=1; i<=nums.size(); i++){
            sum+=i;
        }
        for(auto num:nums){
            sum-=num;
        }
        return sum;
    }
};