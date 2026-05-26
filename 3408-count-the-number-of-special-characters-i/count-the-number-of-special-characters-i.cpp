class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> chars(word.begin(),word.end());
        int count=0;
        for(auto it: chars){
            if(it>='a' && it<='z'){
                if(chars.count(it-32)){
                    count++;
                }
            }
        }
        return count;

    }
};