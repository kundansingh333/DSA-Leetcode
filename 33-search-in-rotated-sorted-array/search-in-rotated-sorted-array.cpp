class Solution {
public:
    int search(vector<int>& nums, int target) {


        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]==target){
        //         return i;
        //     }
        // }
        // return -1;











        int low=0;
        int high=nums.size()-1;
        int n=nums.size();
        int idx=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[n-1]){
                low=mid+1;
            }else{
                idx=mid;
                high=mid-1;
            }
        }
        int f_low=0;
        int f_high=idx-1;

        while(f_low<=f_high){
            int mid=f_low+(f_high-f_low)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                f_low=mid+1;
            }else{
                f_high=mid-1;
            }
        }


        int s_low=idx;
        int s_high=n-1;


        while(s_low<=s_high){
            int mid=s_low+(s_high-s_low)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                s_low=mid+1;
            }else{
                s_high=mid-1;
            }
        }
        return -1;

    }
};