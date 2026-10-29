class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int n=s.length();
        // int maxi=INT_MIN;
        // for(int i=0; i<n; i++){
        //     int hash[256]={0};
        //     for(int j=i;j<n; j++){
        //         if(hash[s[j]]==1) break;
        //         int len=j-i+1;
        //         maxi=max(maxi,len);
        //         hash[s[j]]=1;
        //     }
        // }
        // return maxi;
        vector<int>hash(256,-1);
        int l=0;
        int r=0;
        int n=s.length();
        int len=0;
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            int curr_len=r-l+1;
            len=max(curr_len,len);
            hash[s[r]]=r;
            r++;
        }
        return len;
    }
};