class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>freq(26,0);
        int i=0,j=0;
        int maxLen=0;
        int n=s.length();
        while(j<n){
            freq[s[j]-'a']++;
            while(freq[s[j]-'a']>2){
                freq[s[i]-'a']--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};