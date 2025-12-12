class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx=haystack.find(needle);
        if(idx!=string::npos){
            return idx;
        }
        return -1;
    }
};