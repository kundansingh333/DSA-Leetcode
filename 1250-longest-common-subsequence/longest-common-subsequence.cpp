class Solution {
public:
    vector<vector<int>>t=vector<vector<int>>(1001,vector<int>(1001,-1));
    int lcs(string &t1,string &t2, int n, int m){
        //base case 
        if(n==0 || m==0){
            return 0;
        }
        if(t[n][m]!=-1){
            return t[n][m];
        }
        //choice diagram
        if(t1[n-1]==t2[m-1]){
            return t[n][m] = 1+lcs(t1,t2,n-1,m-1);
        }else{
            return t[n][m] = max(lcs(t1,t2,n,m-1),lcs(t1,t2,n-1,m));
        }

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        return lcs(text1,text2,n,m);
        
    }
};