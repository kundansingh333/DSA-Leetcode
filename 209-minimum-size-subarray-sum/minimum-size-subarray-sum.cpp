class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // int mini=INT_MAX;
        // for(int i=0; i<nums.size(); i++){
        //     int sum=0;
        //     int count=0;
            
        //     for(int j=i; j<nums.size(); j++){
        //         count++;
        //         sum+=nums[j];
        //         if(sum>=target){
        //             mini=min(mini,count);
        //         }
                
        //     }
        // }
        // return mini==INT_MAX?0:mini;

        int i=0;
        int n=nums.size();
        int mini=INT_MAX;
        int sum=0;
        for(int j=0; j<n; j++){
            sum+=nums[j];
            while(sum>=target){
                mini=min(mini,j-i+1);
                sum-=nums[i];
                i++;
            }
        }
        return mini==INT_MAX?0:mini;
    }
};