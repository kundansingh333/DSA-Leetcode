class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=n-1;
        int maxi=INT_MIN;
        while(i<j){
            int c_sum=nums[i]+nums[j];
            maxi=max(c_sum,maxi);
            i++;
            j--;
        }
        return maxi;
    }
};