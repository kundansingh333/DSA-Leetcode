class Solution {
public:
    bool checkOnesSegment(string s) {
        // bool flag=true;
        // for(int i=s.length()-1; i>=0; i--){
        //     if(s[i]!='0'){
        //         flag=false;
        //         break;
        //     }else{
        //         return true;
        //     }

        // }
        // return flag;
        int count = 1;
        for(int i=1; i<s.length(); i++){
            if(s[i]=='1' && s[i-1]!='1'){
                count++;
            }
        }
        return count==1?true:false;
    }
};