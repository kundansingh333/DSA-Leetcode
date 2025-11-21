class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int total=0;
        for(char x='a';x<='z';++x){
            size_t first_idx=s.find(x);
            size_t last_idx=s.rfind(x);
            if(first_idx < last_idx){
                unordered_set<char> unique_middle_char;
                for(int i=first_idx+1; i<last_idx; i++){
                    unique_middle_char.insert(s[i]);
                }
                total+=unique_middle_char.size();
            }
        }
        return total;
    }
};