class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int balance_var=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='L'){
                balance_var++;
            }else{
                balance_var--;
            }
            if(balance_var==0){
                ans++;
            }
        }
        return ans;
    }
};