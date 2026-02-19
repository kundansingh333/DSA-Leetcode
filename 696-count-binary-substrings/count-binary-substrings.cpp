class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length();
        int prev_length=0;
        int current_length=1;

        int count =0;
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                current_length++;
            }else{
                count+=min(prev_length,current_length);
                prev_length=current_length;
                current_length=1;

            }
            

        }
        count+=min(prev_length,current_length);
        return count;
    }
};