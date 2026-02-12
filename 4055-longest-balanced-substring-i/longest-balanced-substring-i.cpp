class Solution {
public:
    int longestBalanced(string s) {
        int max_len=0;    
        for(int i=0; i<s.size(); i++){
            vector<int> mp(26,0);
            // mp[s[i]-'a']++;
            for(int j=i; j<s.size(); j++){
                mp[s[j]-'a']++;
                bool isBalanced=true;
                int targetFreq=-1;
                for(int k=0; k<26; k++){
                    if(mp[k]>0){
                        if(targetFreq ==-1){
                            targetFreq=mp[k];
                        }else if(mp[k]!=targetFreq){
                            isBalanced=false;
                            break;
                        }
                    }
                
                }
                if(isBalanced){
                    int len=j-i+1;
                    max_len=max(len,max_len);
                }
            }
        }
        return max_len;
    }
};