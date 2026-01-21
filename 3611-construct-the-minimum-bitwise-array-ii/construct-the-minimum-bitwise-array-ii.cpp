class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> result(n);
        for(int i=0; i<n; i++){
            int val=nums[i];
            if(val%2==0){
                result[i]=-1;
            }else{
                int negVal=~val;
                long long zeroBit=negVal & -negVal;
                result[i]=val-(zeroBit>>1);
            }
        }
        return result;
    }
};