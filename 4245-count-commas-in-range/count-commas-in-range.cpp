class Solution {
public:
    int countCommas(int n) {
        // string s=to_string(n);
        // int len=s.length();
        // int count=0;
        // while(len>=4){
        //     count++;
        //     n--;
        //     s=to_string(n);
        //     len=s.length();
        // }
        // return count;
        return max(0,n-999);
    }
};