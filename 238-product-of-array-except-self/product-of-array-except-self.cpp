class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int product=1;
        // int n=nums.size();
        // int zero_counts=0;
        // for(auto it:nums){
        //     if(it==0){
        //         zero_counts++;
        //     }else{
        //         product*=it;
        //     }
        // }
        // vector<int>answer(n,0);
        // for(int i=0; i<nums.size(); i++){
        //     if(zero_counts>1){
        //         return answer;
        //     }else{
        //         if(zero_counts==1){
        //             if(nums[i]==0){
        //                 answer[i]=product;
        //             }
        //         }else{
        //             answer[i]=product/nums[i];
        //         }
        //     }
        // }
        // return answer;



        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> answer(n);
        
        // 1. Build Left Array
        left[0] = 1; // Nothing to the left of first element
        for(int i = 1; i < n; i++){
            left[i] = left[i-1] * nums[i-1];
        }
        
        // 2. Build Right Array
        right[n-1] = 1; // Nothing to the right of last element
        for(int i = n-2; i >= 0; i--){
            right[i] = right[i+1] * nums[i+1];
        }
        
        // 3. Construct Answer
        for(int i = 0; i < n; i++){
            answer[i] = left[i] * right[i];
        }
        
        return answer;
    }
};