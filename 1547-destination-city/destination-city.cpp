class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> starting;
        for(auto it:paths){
            starting.insert(it[0]);
        }
        for(auto it:paths){
            string destination = it[1];
            if(starting.count(destination)==0){
                return destination;
            }
        }
        return "";
    }
};