class Solution {
public:
    bool isValid=false;
    int t[101][101];
    bool solve(int i, int open, string s, int n){
        if(i==n){
            return open==0;
        }
        if(t[i][open]!=-1){
            return t[i][open];
        }
        if(s[i]=='('){
            isValid |=solve(i+1,open+1,s,n);
        }else if(s[i]=='*'){
            isValid |= solve(i+1,open+1,s,n);
            isValid |= solve(i+1,open,s,n);
            if(open>0){
                isValid |= solve(i+1,open-1,s,n);
            }
            
        }else if(open>0){
            isValid |= solve(i+1,open-1,s,n);
        }
        return t[i][open]= isValid;
    }
    bool checkValidString(string s) {
        memset(t,-1,sizeof(t));
        int n=s.length();
        return solve(0,0,s,n);
    }
};