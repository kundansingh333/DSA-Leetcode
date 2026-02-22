class Solution {
public:
    int binaryGap(int n) {
        int count=0;
        int maxi=0;
        while(n>0){
            int last_bit=n&1;
            if(count>=1 && last_bit==0){
                count++ ;
            }
            if(last_bit==1){
                maxi=max(maxi,count);
                count=1;
            }
            n>>=1;
        }
        return maxi;
    }
};