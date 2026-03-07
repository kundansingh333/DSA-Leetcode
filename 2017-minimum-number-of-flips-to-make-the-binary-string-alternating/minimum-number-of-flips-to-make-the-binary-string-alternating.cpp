class Solution {
public:
    int minFlips(string s) {
        // int len= s.length();
        // int count=0;
        // int mini=INT_MAX;
        // int m=0;
        // while(m<len){
            
        //     for(int i=1; i<len; i++){
        //         if(s[0]=='1'){
        //             if(i%2==0 && s[i]!='1'){
        //                 count++;
        //             }
        //             if(i%2!=0 && s[i]=='1'){
        //                 count++;
        //             }
        //         }
        //         if(s[0]=='0'){
        //             if(i%2==0 && s[i]!='0'){
        //                 count++;
        //             }
        //             if(i%2!=0 && s[i]=='0'){
        //                 count++;
        //             }
        //         }
        //     }
        //     s=s.substr(1)+s[0];
        //     mini=min(count,mini);   
        //     m++;
        // }
        
        // return mini;

        int n=s.length();
        

        string s2=s+s;
        string alt1="";
        string alt2="";
        for(int i=0; i<s2.length(); i++){
            alt1 +=(i%2==0)?"0":"1";
            alt2 +=(i%2==0)?"1":"0";

        }

        int result=INT_MAX;
        int diff1=0;
        int diff2=0;

        for(int i=0; i<s2.length(); i++){
            if(s2[i] != alt1[i]) diff1++;
            if(s2[i] != alt2[i]) diff2++;

            if(i>=n){
                if(s2[i-n] != alt1[i-n] ) diff1--;
                if(s2[i-n] != alt2[i-n] ) diff2--;

            }
            if(i>=n-1){
                result=min({result,diff1,diff2});
            }
        }
        return result;

    }
};