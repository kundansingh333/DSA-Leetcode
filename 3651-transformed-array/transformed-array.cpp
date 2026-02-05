class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n= nums.size();
        vector<int>result(n);
        for(int i=0; i<nums.size(); i++){
            // int index;
            if(nums[i]>0){
                int index = i+nums[i];
                index = index % n;
                result[i]=nums[index];
            }else if(nums[i]<0){
                int index=(i+nums[i]);
                index= index % n;
                if(index<0){
                    index+=n;
                }
                result[i]=nums[index];
            }else{
                result[i]=nums[i];
            }
            
        }
        return result;
    }
};