class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        // int i=0; 
        // int j=1;
        // int n=nums.size();
        // int sum=nums[0];
        // while(j<n){
        //     if(nums[j]!=nums[i]){
        //         sum+=nums[j];
        //     }
            
        // }
        int sum=0;
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(int i=0; i<mp.size(); i++){
            if(mp[i]==1){
                sum+=i;
            }
        }
        return sum;

    }
};