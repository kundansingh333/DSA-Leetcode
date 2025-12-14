class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        // int f_mid=0;
        // bool isAvail=nums.find(nums.begin(),nums.end(),target);
        while(left<=right){
            // int mid=left+(right-left)/2;
            int mid=(left+right)/2;
            if(nums[mid]==target){
                // f_mid=mid;
                return mid;
            }
            if(nums[mid]>target){

                right=mid-1;
            }else if(nums[mid]<target){
                left=mid+1;
            }
            
            // left++;
        }
        // return f_mid;
        return left;
    }
};