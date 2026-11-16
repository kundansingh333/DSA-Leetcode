class Solution {
public:
    string fun(string &sub){
        int sum=0;
        for(auto ch:sub){
            sum+=(ch-'0');
        }
        return to_string(sum);
    }
    string digitSum(string s, int k) {

       
        while(s.length()>k){
            string temp="";
            for(int i=0; i<s.length(); i+=k){
                string sub=s.substr(i,k);
                string new_s=fun(sub);
                temp+=new_s;
            }
            s=temp;
        }
        return s;
    }
};