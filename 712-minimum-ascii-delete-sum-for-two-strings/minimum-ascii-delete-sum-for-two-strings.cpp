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
            return getSum(s2,m);
        }
        if(m==0){
            return getSum(s1,n);
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
        int n=s1.length();
        int m=s2.length();
        t.assign(n+1,vector<int>(m+1,-1));
        return lcs(s1,s2,n,m);
    }
};