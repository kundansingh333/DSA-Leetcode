class Solution {
public:
    int minOperations(string s) {
        int zero_count=0;
        int one_count=0;
        for(int i=0;i<s.length(); i++){
            if(i%2==0 && s[i]=='0'){
                continue;
            }
            else if(i%2==0 && s[i]!='0'){
                // s[i]='0';
                zero_count++;
            }
            if(i%2!=0 && s[i]=='1'){
                continue;
            }else if(i%2!=0 && s[i]!='1'){
                // s[i]='1';
                zero_count++;
            }

        }


        for(int i=0;i<s.length(); i++){
            if(i%2==0 && s[i]=='1'){
                continue;
            }
            if(i%2==0 && s[i]!='1'){
                // s[i]='1';
                one_count++;
            }


            if(i%2!=0 && s[i]=='0'){
                continue;
            }else if(i%2!=0 && s[i]!='0'){
                // s[i]='0';
                one_count++;
            }

        }
        return min(zero_count,one_count);
    }
};