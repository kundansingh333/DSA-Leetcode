class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0;
        int b=0;
        int c=0;
        int count=0;
        int i=0;

        int n=s.length();
        for(int j=0; j<n; j++){
            if(s[j]=='a') a++;
            if(s[j]=='b') b++;
            if(s[j]=='c') c++;
            while(a>0 && b>0 && c>0){
                count+=n-j;
                if(s[i]=='a') a--;
                if(s[i]=='b') b--;
                if(s[i]=='c') c--;
                i++;
            }
        }
        return count;
    }
};