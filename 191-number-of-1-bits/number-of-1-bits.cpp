class Solution {
public:
    int hammingWeight(int n) {
        int res=0;
        while(n>0){
            int curr=n&1;
            if(curr==1){
                res++;
            }
            n >>= 1;
        }
        return res;
    }
};