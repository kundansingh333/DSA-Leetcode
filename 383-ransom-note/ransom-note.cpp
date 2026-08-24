class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(auto ch:magazine){
            mp1[ch]++;
        }
        for(auto &ch:ransomNote){
            mp2[ch]++;
        }

        // for(auto it=mp2.begin(); it!=mp2.end(); it++){
        //     if(mp1[it->first]<it->second) return false;
        // }
        // return true;
        for(auto [key,value]:mp2){
            if(mp1[key]<value){
                return false;
            }
        }
        return true;



    }
};