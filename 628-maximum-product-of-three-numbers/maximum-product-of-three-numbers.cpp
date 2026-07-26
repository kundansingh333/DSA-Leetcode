class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        // if(nums==3) return nums[n-1]*nums[n-2]*nums[n-3];
        sort(nums.begin(),nums.end());
        int nums1=nums[n-1]*nums[0]*nums[1];
        int nums2=nums[n-1]*nums[n-2]*nums[n-3];
        int nums3=nums[n-1]*nums[n-2]*nums[n-3];
        int maxi=max(nums1,nums2);
        return max(maxi,nums3);
    }
};