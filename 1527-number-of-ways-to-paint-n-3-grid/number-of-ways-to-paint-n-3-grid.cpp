class Solution {
public:
    long long M=1000000007;
    int numOfWays(int n) {
        
        if(n==0) return 0;
        long long aba=6; //ways
        long long abc=6;//ways
        n--;
        while(n>0){
            long long next_aba= (3*aba + 2*abc) %M;
            long long next_abc=(2*aba + 2*abc) %M;
            aba=next_aba;
            abc=next_abc;
            n--;
        }
        return (aba+abc)%M;
    }
};