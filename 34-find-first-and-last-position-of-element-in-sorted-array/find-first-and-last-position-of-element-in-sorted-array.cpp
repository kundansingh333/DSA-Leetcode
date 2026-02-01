class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    //     int start=-1;
    //     int end=-1;
    //    for(int i=0; i<nums.size(); i++){
    //         if(nums[i]==target && start == -1){
    //             start=i;
    //         }
    //         if(nums[i]==target){
    //             end=i;
    //         }
    //     }
    //     return {start,end};

        int low=0;
        int high=nums.size()-1;
        int start=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                start=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        
        int n_low=0;
        int n_high=nums.size()-1;
        int end=-1;
        while(n_low<=n_high){
            int mid=n_low+(n_high-n_low)/2;
            if(nums[mid]==target){
                end=mid;
                n_low=mid+1;
            }
            else if(nums[mid]<target){
                n_low=mid+1;
            }else{
                n_high=mid-1;
            }
        }
        return {start,end};


    }
};