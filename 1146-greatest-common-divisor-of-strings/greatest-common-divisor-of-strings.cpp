class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1=str1.length();
        int l2=str2.length();

        string conc_str1 = str1+str2;
        string conc_str2 = str2+str1;
        int count=0;
        if(conc_str1==conc_str2){
            count = gcd(l1,l2);

        }else{
            return "";
        }
        
        string ans=str1.substr(0,count);
        return ans;


    }
};