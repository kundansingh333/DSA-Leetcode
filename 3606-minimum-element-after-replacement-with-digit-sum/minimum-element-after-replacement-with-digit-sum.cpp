class Solution {
public:
    int getDigits(int num){
        int s=0;
        while(num>0){
            int rem=num%10;
            s+=rem;
            num/=10;
        }
        return s;
        
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            int number= getDigits(nums[i]);
            mini=min(mini,number);
        }
        return mini;
    }
};