class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(auto it:nums){
        //     mp[it]++;
        // }
        // for(auto it:nums){
        //     if(mp[it]>=2){
        //         return true;
        //     }
        // }
        // return false;
        unordered_set<int>seen;
        for(auto it:nums){
            if(seen.find(it)!=seen.end()){
                return true;
            }
            seen.insert(it);
        }
        return false;
    }
};