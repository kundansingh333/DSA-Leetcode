class Solution {
public:
    string convert2Binary(int n){
        string res="";
        while(n!=1){
            if(n%2==1) res+="1";
            else res+="0";
            n/=2;
        }
        res+="1";
        reverse(res.begin(),res.end());
        return res;
    }
    int convert2String(string s){
        int len=s.length(); 
        int num=0;
        int p2=1;
        long long MOD=1000000007;
        for(int i=len-1; i>=0; i--){
            if(s[i]=='1'){
                num=(num+p2)%MOD;
            }
            p2=(p2*2)%MOD;
        }
        return num;
    }
    int concatenatedBinary(int n) {
        string s="";
        for(int i=1; i<=n; i++){
            s+=convert2Binary(i);
        }
        int final_res=convert2String(s);
        return final_res;


    }
};