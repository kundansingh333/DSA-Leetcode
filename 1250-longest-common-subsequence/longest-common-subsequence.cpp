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
        // int n=text1.length();
        // int m=text2.length();
        // return lcs(text1,text2,n,m);

        int n=text1.length();
        int m=text2.length();

        vector<vector<int>>t(n+1,vector<int>(m+1));

        //initialization
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }

        //choice diagram
        for(int i=1; i<t.size(); i++){
            for(int j=1; j<t[0].size(); j++){
                if(text1[i-1]==text2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return t[n][m];


        
    }
};