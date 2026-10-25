class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>morse={
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for(auto word:words){
            string morse_code="";
            for(auto c:word){
                morse_code+=morse[c-'a'];
            }
            s.insert(morse_code);
        }
        return s.size();
        
    }
};