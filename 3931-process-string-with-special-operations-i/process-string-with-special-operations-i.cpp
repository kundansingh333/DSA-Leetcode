class Solution {
public:
    string result="";
    void remove(){
        result.pop_back();
    }
    void add(char ch){
        result+=ch;
    }
    void rever(){
        reverse(result.begin(),result.end());
    }
    void duplicate(){
        result+=result;
    }
    string processStr(string s) {
        for(int i=0; i<s.length(); i++){
            if(s[i]=='*' && result.length()!=0){
                remove();
            }else if(s[i]=='%'){
                rever();
            }else if(s[i]=='#'){
                duplicate();
            }else if(s[i]>='a' && s[i]<='z'){
                add(s[i]);
            }
        }
        return result;
    }
};