class Solution {
public:
    // int toNumber(string s){
    //     int p2=1;
    //     int num=0;
    //     int len=s.length()-1;
    //     for(int i=len; i>=0;i--){
    //         if(s[i]=='1'){
    //             num+=p2;
    //         }
    //         p2=p2*2;
    //     }
    //     return num;
    // }
    string addBinary(string a, string b) {
        int len_a=a.length()-1;
        int len_b=b.length()-1;
        int carry=0;
        string ans="";
        while(len_a>=0 || len_b>=0 || carry==1){
            int digit1=(len_a >=0 )?a[len_a]-'0':0;
            int digit2=(len_b >=0 )?b[len_b]-'0':0;

            int sum=digit1+digit2+carry;

            ans+=to_string(sum%2);
            carry=sum/2;
            len_a--;
            len_b--;

        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};