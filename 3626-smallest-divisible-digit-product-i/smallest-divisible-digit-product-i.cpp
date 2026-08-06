class Solution {
public:
    int fun(int n){
        int p=1;
        while(n>0){
            int rem=n%10;
            p=p*rem;
            n/=10;
        }
        return p;
        
    }
    int smallestNumber(int n, int t) {
        
        while(n){
            int product=fun(n);
            if(product%t==0){
                return n;
            }
            n++;
        }
        return 0;
    }
};