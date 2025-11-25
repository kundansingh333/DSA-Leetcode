class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int count=0;
        int remainder=0;
        int length=0;

        for(int i=0; i<k; i++){
            if(k%5==0 || k%2==0){
                return -1;
            }
            remainder=(remainder*10+1)%k;
            if(remainder==0){
                length=i+1;
                break;
            }
        }
        return length;
        
    }
};