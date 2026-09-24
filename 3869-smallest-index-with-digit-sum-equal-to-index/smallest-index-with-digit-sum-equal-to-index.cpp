class Solution {
public:
    int fun(int num){
        int sum=0;
        while(num>0){
            int rem=num%10;
            sum+=rem;
            num/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(fun(nums[i])==i){
                return i;
            }
        }
        return -1;
    }
};