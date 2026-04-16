class Solution {
public:
    bool isAnagram(string s, string t) {
        int s1=s.length();
        int t2=t.length();
        if(s1!=t2){
            return false;
        }
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        for(int i=0; i<t.length(); i++){
            if(mp[t[i]]==false){
                return false;
            }
            mp[t[i]]--;
        }
        return true;
    }
};