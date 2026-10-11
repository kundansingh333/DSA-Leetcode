class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(n%(i+1)==0){
                total+=pow(nums[i],2);
            }
        }
        return total;
    }
};