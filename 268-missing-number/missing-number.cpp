class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))/2;
        // for(int i=1; i<=nums.size(); i++){
        //     sum+=i;
        // }
        
        for(auto num:nums){
            sum-=num;
        }
        return sum;
        
    }
};