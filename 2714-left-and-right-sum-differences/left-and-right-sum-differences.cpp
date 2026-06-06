class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftSum;
        vector<int>rightSum(n);
        
        int c_l_sum=0;
        leftSum.push_back(c_l_sum);
        for(int i=0; i<n-1; i++){
            c_l_sum+=nums[i];
            leftSum.push_back(c_l_sum);
        }

        int c_r_sum=0;
        rightSum[n-1]=c_r_sum;
        for(int i=n-1; i>0; i--){
            c_r_sum+=nums[i];
            rightSum[i-1]=c_r_sum;
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            ans.push_back(abs(leftSum[i]-rightSum[i]));
        }
        return ans;

    }
};