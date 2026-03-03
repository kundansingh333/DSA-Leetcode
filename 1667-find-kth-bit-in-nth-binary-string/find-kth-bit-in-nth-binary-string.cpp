class Solution {
public:
    string inverted_st(string s){
        for(int i=0; i<s.length(); i++){
            s[i]^=1;
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string old_s="0";
        string current_s="";
        for(int i=1; i<=n; i++){
            string str=inverted_st(old_s);
            reverse(str.begin(),str.end());
            current_s=old_s+"1"+str;
            old_s=current_s;
        }
        return current_s[k-1];
       
    }
};