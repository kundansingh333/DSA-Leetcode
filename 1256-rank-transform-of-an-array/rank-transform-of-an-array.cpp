class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sorted=arr;
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int>mp;
        int count=0;
        for(auto num:sorted){
            if(mp.find(num)==mp.end()){
                count++;
                mp[num]=count;
            }
        }
        vector<int>ans;
        for(auto it:arr){
            ans.push_back(mp[it]);
        }
        return ans;
        // return sorted;
    }
};