class Solution {
public:
    string minWindow(string s, string t) {
        int i=0;
        int j=0;
        int start=-1;
        int mini=INT_MAX;
        map<char,int>mp;
        for(auto c:t){
            mp[c]++;
        }
        int count=mp.size();
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            while(count==0){
                if(j-i+1<mini){
                    mini=j-i+1;
                    start=i;
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        return start==-1?"":s.substr(start,mini);
    }
};