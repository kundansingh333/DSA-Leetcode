class Solution {
public:
    void rotate(string &s,int n){
        reverse(s.begin(),s.begin()+1);
        reverse(s.begin()+1,s.end());
        reverse(s.begin(),s.end());
    }
    bool rotateString(string s, string goal) {
        int n=s.length();
        for(int i=0; i<s.length(); i++){
            if(s==goal){
                return true;
            }
            rotate(s,n);
        }
        return false;
    }
    
};