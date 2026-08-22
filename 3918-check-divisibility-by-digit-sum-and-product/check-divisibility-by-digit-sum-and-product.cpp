class Solution {
public:

    int digitSum(int n){
        int sum=0;
        while(n>0){
            int rem=n%10;
            sum+=rem;
            n/=10;
        }
        return sum;
    }
    int digitProduct(int n){
        int product=1;
        while(n>0){
            int rem=n%10;
            product*=rem;
            n/=10;
        }
        return product;
    }
    bool checkDivisibility(int n) {
        int sum=digitSum(n);
        int product=digitProduct(n);
        int num=sum+product;
        return n%num==0;
    }
};