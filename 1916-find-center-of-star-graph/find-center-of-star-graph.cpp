class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a=edges[0][0];
        int b=edges[0][1];
        unordered_map<int,int>mp;
        mp[a]=1;
        mp[b]=1;
        for(int i=1; i<edges.size(); i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        for(auto it:mp){
            if(it.second>=2){
                return it.first;
            }
        }
        return 0;
    }

};