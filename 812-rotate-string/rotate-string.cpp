class Solution {
public:
    void rotate(string &s,int n){
        reverse(s.begin(),s.begin()+1);
        reverse(s.begin()+1,s.end());
        reverse(s.begin(),s.end());
    }
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        if(s==goal) return true;
        int n=s.length();
        for(int i=0; i<s.length(); i++){
            rotate(s,n);
            if(s==goal){
                return true;
            }
            
        }
        return false;
    }
    
};