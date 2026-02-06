class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int left=0;
        int maxkeep=0;
        for(int right=0; right<n; right++){
            while((long long)nums[right]>(long long)nums[left]*k){
                left++;
            }
            maxkeep=max(maxkeep,right-left+1);
        }
        return n-maxkeep;

    }
};