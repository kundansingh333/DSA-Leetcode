class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count=0;
        int maxi=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0; i<n; i++){
            int number=maxi-nums[i];
            count+=number;
        }
        return count;
    }
};