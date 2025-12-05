class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
         if(n<2) return 0;


        vector<int> prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        } 
        int count=0;
        
        for(int i=0; i<n-1; i++){
            int leftSum=prefixSum[i];
            int rightSum=prefixSum[n-1]-prefixSum[i];

            int diff=leftSum-rightSum;

            if(diff%2==0){
                count++;
            }
        }
        return count;



        
    }
};