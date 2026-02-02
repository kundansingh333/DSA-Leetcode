class Solution {
public:
    int findMin(vector<int>& nums) {
        // int mini=INT_MAX;
        // for(int i=0; i<nums.size(); i++){
        //     mini=min(mini,nums[i]);
        // }
        // return mini;
        
        int low=0;
        int n= nums.size()-1;
        int high=nums.size()-1;
        int res;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[n]){
                low=mid+1;
            }else{
                res=mid;
                high=mid-1;
            }
        }
        return nums[res];

    }
};