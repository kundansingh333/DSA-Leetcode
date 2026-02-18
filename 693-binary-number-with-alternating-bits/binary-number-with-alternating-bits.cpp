class Solution {
public:
    bool hasAlternatingBits(int n) {
        int curr=n&1;
        while(n>0){
            n >>= 1;
            int next=n&1;
            if(curr==next){
                return false;
            }
            curr=next;
        }
        return true;
    }
};