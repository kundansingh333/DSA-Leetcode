class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int> mp;
        unordered_set<int>counts;
        
        for(auto it:arr){
            mp[it]++;
        }
        for(auto it:mp){
            int freq=it.second;
            if(counts.count(freq)){
                return false;
            }
            counts.insert(freq);
        }
        return true;
    }
};