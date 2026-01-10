class Solution {
public:
    vector<vector<int>>t;
    int lcs(string &s1,string &s2,int n, int m){
        if(n==0 || m==0){
            return 0;
        }
        if(t[n][m]!=-1){
            return t[n][m];
        }

        if(s1[n-1]==s2[m-1]){
            return t[n][m] = 1+lcs(s1,s2,n-1,m-1);
        }else{
            return t[n][m] = max(lcs(s1,s2,n,m-1),lcs(s1,s2,n-1,m));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.length();
        int m=text2.length();
        t.assign(n+1,vector<int>(m+1,-1));
        int result=lcs(text1,text2,n,m);
        return result;
    }
};