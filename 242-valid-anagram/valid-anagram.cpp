class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length()){
            return false;
        }


        // ***************


        // unordered_map<char,int>mp;
        // for(auto it:s){
        //     mp[it]++;
        // }
        // for(int i=0; i<t.length(); i++){
        //     if(mp[t[i]]==false){
        //         return false;
        //     }
        //     mp[t[i]]--;
        // }
        // return true;


        // **************
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // for(int i=0; i<t.length(); i++){
        //     if(s[i]!=t[i]){
        //         return false;
        //     }
        // }
        // return true;


        // *******************

        int count[26]={0};
        for(int i=0; i<s.length(); i++){
            count[s[i]-'a']++;
        }
        for(int i=0; i<t.length(); i++){
            if(count[t[i]-'a']==0){
                return false;
            }
            count[t[i]-'a']--;
        }
        return true;
    }
};