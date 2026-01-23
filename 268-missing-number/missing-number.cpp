class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n=nums.size();
        // int sum=(n*(n+1))/2;
        // for(auto num:nums){
        //     sum-=num;
        // }
        // return sum;


        // usig XOR
        int res= nums.size();
        for(int i=0; i<nums.size(); i++){
            res^=i;
            res^=nums[i];

        }
        return res;
        
    }
};