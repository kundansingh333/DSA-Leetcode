class Solution {
public:
    int mirrorDistance(int n) {
        int m=0;
        int k=n;
        while(n>0){
            int remain=n%10;
            m=m*10+remain;
            n=n/10;
        }
        return abs(k-m);

    }
};