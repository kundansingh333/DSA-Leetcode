class Solution {
public:
   
    int secondHighest(string s) {
        set<int>arr;
        for(auto ch:s){
            if(isdigit(ch)){
                arr.insert(ch-'0');
            }
        }
        if(arr.size()<2) return -1;
        auto it=arr.rbegin();
        it++;
        return *it;
        
        
    }
};