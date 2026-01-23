class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int sum=0;
        // for(int i=1; i<=nums.size(); i++){
        //     sum+=i;
        // }
        // for(auto num:nums){
        //     sum-=num;
        // }
        // return sum;
        int n = nums.size();
        sort(nums.begin(),nums.end());        
        for(int i = 0; i<n; i++){
            if(nums[i]!=i) return i;
        }
        return nums[nums.size()-1]+1;
    }
};