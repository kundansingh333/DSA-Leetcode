class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return "0";
        bool is_negative=num<0;
        int nums=abs((long long)num);
        string res="";
        while(nums>0){
            res+=to_string(nums%7);
            nums/=7;
        }
        if(is_negative){
            res+='-';
        }
        reverse(res.begin(),res.end());
        return res;
    }
};