class Solution {
public:
    
    int minChanges(string s) {
        int n=s.length();
        int count=0;
        for(int i=0; i<n-1; i+=2){
            // for(int j=0; j<2;j++){
            //     i
            // }
            if(s[i]!=s[i+1]){
                count++;
            }
        }
        return count;
    }
};