class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.length()-1;
        int j=num2.length()-1;
        int carry=0;
        string res="";
        while(i>=0 || j>=0 || carry>0){

            int d1=(i>=0)?num1[i]-'0':0;
            int d2=(j>=0)?num2[j]-'0':0;

            int sum=d1+d2+carry;
            res+=to_string(sum%10);
            carry=sum/10;
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};