class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> upper(26,false);
        vector<bool> lower(26,false);

        for(auto it:word){
            if(it>='a' && it<='z'){
                if(upper[it-'a']){
                    lower[it-'a']=false;
                }else{
                    lower[it-'a']=true;
                }
            }else{
                upper[it-'A']=true;
            }
        }
        int ans=0;
        for(int i=0; i<26; i++){
            if(upper[i] && lower[i]){
                ans++;
            }
        }
        return ans;
    }
};