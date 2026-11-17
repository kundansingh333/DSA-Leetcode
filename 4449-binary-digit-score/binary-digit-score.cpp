class Solution {
public:
    int toBinary(int a){
        string bin="";
        while(a>0){
            bin+=(a&1)?'1':'0';
            a>>=1;
        }
        int sum=0;
        for(auto ch:bin){
            sum+=(ch-'0');
        }
        return sum;
    }
    int calculateScore(int a, int b) {
        int s1=toBinary(a);
        int s2=toBinary(b);
        if(s1>=s2){
            return s1*s2;
        }else{
            return s2/s1;
        }
    }
};