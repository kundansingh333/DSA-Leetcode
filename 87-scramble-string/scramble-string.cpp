class Solution {
public:
    unordered_map<string, bool>mp;
    bool solve(string a, string b){
        if(a.compare(b)==0){
            return true;
        }
        if(a.length()<=1){
            return false;
        }
        //makeing the key
        string key=a;
        key.push_back(' ');
        key.append(b);
        //return bool value from the map 
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }


        int n=a.length();
        bool flag=false;
        for(int i=1; i<=n-1; i++){
            bool c1=solve(a.substr(0,i),b.substr(n-i,i))==true && solve(a.substr(i,n-i),b.substr(0,n-i));

            bool c2=solve(a.substr(0,i),b.substr(0,i))==true && solve(a.substr(i,n-i),b.substr(i,n-i))==true;

            if(c1 || c2){
                flag=true;
                break;
            }
        }
        
        
        return mp[key]=flag;
    }
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()){
            return false;
        }
        if(s1.length()==0 && s2.length()==0){
            return true;
        }
        return solve(s1,s2);
    }
};