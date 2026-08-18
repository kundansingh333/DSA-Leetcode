class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
      int n=nums.size();
      if(n==k){
        return *max_element(nums.begin(),nums.end());
      }
      unordered_map<int,int>freq;
      for(auto it:nums){
        freq[it]++;
      }
      
      if(k==1){
        int ans=-1;
        for(auto x:nums){
            if(freq[x]==1){
                ans=max(ans,x);
            }
        }
        return ans;
      }


      int ans=-1;
      if(freq[nums[0]]==1){
        ans= max(ans,nums[0]);
      }
      if(freq[nums[n-1]]==1){
        ans= max(ans,nums[n-1]);
      }
      return ans;
    }
};