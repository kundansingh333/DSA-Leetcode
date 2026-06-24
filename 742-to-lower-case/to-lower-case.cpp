class Solution {
public:
    string toLowerCase(string s) {
        // 
        ranges::transform(s,s.begin(),[](unsigned char c){
            return tolower(c);
        });
        return s;
    }
};