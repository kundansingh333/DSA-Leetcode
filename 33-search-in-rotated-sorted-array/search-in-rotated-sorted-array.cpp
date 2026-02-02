class Solution {
public:
    int search(vector<int>& nums, int target) {


        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;









        // int low=0;
        // int high=nums.size()-1;
        // int n=nums.size();
        // while(low<=high){
        //     int mid=low+(high-low)/2;
        //     if(nums[mid]>nums[n-1]){
        //         if(nums[mid]==target){
        //             return mid;
        //         }else{
        //             low=mid+1;
        //         }
        //     }else{
        //         if(nums[mid]==target){
        //             return mid;
        //         }else{
        //             high=mid-1;
        //         }
        //     }
        // }
        // return -1;
    }
};