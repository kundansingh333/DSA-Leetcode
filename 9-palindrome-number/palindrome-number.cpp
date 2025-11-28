class Solution {
public:
    bool isPalindrome(int x) {
        long long original_num=x;
        long long reversed=0;
        if(x<0) return false;
        while(x>0){
            int last=x%10;
            reversed = reversed*10+last;
            x/=10;
        }
        if(original_num==reversed){
            return true;
        }
        return false;
    }
};