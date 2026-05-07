class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        if(n==1) return 1;
        int i=0;
        int j=n;
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        int ans=0;
        bool hasodd=false;
        
        for(unordered_map<char,int>::iterator it=mp.begin();it!=mp.end(); it++){
            int count=it->second;
            if(count%2==0){
                ans+=it->second;
            }else{
                hasodd=true;
                ans+=count-1;
            }
            
        }
        if(hasodd){
            return ans+1;
        }
        
        return ans;
    }
};