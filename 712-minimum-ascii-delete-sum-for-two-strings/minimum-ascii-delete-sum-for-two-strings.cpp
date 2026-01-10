class Solution {
public:
    vector<vector<int>>t;
    // int sum=0;
    int getSum(string s,int end){
        int sum=0;
        for(int i=0; i<end; i++){
            sum+=s[i];
        }
        return sum;
    }
    int lcs(string &s1,string &s2, int n, int m){
        if(t[n][m]!=-1){
            return t[n][m];
        }
        if(n==0){
            return t[n][m] =  getSum(s2,m);
        }
        if(m==0){
            return t[n][m]= getSum(s1,n);
        }
        
        if(s1[n-1]==s2[m-1]){
            return t[n][m] = lcs(s1,s2,n-1,m-1);
        }else{
            int delete1=(int)s1[n-1]+lcs(s1,s2,n-1,m);
            int delete2=(int)s2[m-1]+lcs(s1,s2,n,m-1);
            return t[n][m] = min(delete1,delete2);
        }

        
    }
    int minimumDeleteSum(string s1, string s2) {
        // int n=s1.length();
        // int m=s2.length();
        // t.assign(n+1,vector<int>(m+1,-1));
        // return lcs(s1,s2,n,m);
        int n = s1.length();
        int m = s2.length();
        
        // DP table of size (n+1) x (m+1)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // 1. Fill Base Case: First Column (s2 is empty)
        // Cost is sum of all characters in s1 so far
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        
        // 2. Fill Base Case: First Row (s1 is empty)
        // Cost is sum of all characters in s2 so far
        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        
        // 3. Fill the rest of the table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                
                // If characters match, no deletion cost added for this step
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } 
                // If mismatch, delete the one that results in lower total cost
                else {
                    int deleteS1 = dp[i-1][j] + s1[i-1];
                    int deleteS2 = dp[i][j-1] + s2[j-1];
                    dp[i][j] = min(deleteS1, deleteS2);
                }
            }
        }
        
        return dp[n][m];
    }
};