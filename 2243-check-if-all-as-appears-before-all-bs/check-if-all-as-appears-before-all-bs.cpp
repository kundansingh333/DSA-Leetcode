class Solution {
public:
    bool checkString(string s) {
        int a=0;
        for(int i=0; i<s.length()-1; i++){
            if(s[i]>s[i+1]){
                return false;
            }
        }
        return true;
    }
};