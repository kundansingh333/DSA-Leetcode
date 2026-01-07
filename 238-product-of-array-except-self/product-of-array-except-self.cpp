class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        int n=nums.size();
        int zero_counts=0;
        for(auto it:nums){
            if(it==0){
                zero_counts++;
            }else{
                product*=it;
            }
        }
        vector<int>answer(n,0);
        for(int i=0; i<nums.size(); i++){
            if(zero_counts>1){
                return answer;
            }else{
                if(zero_counts==1){
                    if(nums[i]==0){
                        answer[i]=product;
                    }
                }else{
                    answer[i]=product/nums[i];
                }
            }
        }
        return answer;
    }
};