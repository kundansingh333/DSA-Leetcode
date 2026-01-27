class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //    int n= nums.size();
    //    for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(nums[i]+nums[j]==target){
    //             return {i,j};
    //         }
    //     }
    //    } 
    //    return {-1,-1};


    unordered_map<int,int>mp;
    for(int i=0; i<nums.size(); i++){
        int complement=target-nums[i];
        if(mp.find(complement)!=mp.end()){
            return {mp[complement],i};
        }
        mp[nums[i]]=i;
    }
    return {};

    // int n=nums.size();
    // int i=0;
    // int j=n-1;


    // vector<vector<int>>ans;
    // while(i<j){
    //     int sum=nums[i]+nums[j];
    //     if(sum<target){
    //         i++;
    //     }else if(sum>target){
    //         j++;
    //     }else{
    //         ans.push_back({nums[i],nums[j]});
    //     }
    // }
    // return ans;

    }
};