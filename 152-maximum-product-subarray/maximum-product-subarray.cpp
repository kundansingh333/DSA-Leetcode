class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int max_ending=nums[0];
        int min_ending=nums[0];
        int n=nums.size();

        for(int i=1; i<n; i++){
            int v1=nums[i];
            int v2=nums[i]*max_ending;
            int v3=nums[i]*min_ending;

            max_ending=max(v1,max(v2,v3));
            min_ending=min(v1,min(v2,v3));

            ans=max(ans,max(max_ending,min_ending));
        }
        return ans;
    }
};