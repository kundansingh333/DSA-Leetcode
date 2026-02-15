class Solution {
public:
    string addBinary(string a, string b) {
        int len_a=a.length()-1;
        int len_b=b.length()-1;
        int carry=0;
        string ans="";
        while(len_a>=0 || len_b>=0 || carry==1){
            int dig1=(len_a>=0)?a[len_a]-'0':0;
            int dig2=(len_b>=0)?b[len_b]-'0':0;
            int sum=dig1+dig2+carry;
            ans+=to_string(sum%2);
            carry=sum/2;
            len_a--;
            len_b--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};