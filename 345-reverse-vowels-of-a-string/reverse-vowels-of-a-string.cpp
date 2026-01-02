class Solution {
public:
    bool isVowel(char c){
        c=tolower(c);
        return 'a'==c || 'e'==c || 'i'==c || 'o'==c || 'u'==c;
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            // s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' &&
            //     s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U' 
            if(
                !isVowel(s[i])
                ){
                    i++;
                    continue;
                }

                // s[j]!='a' && s[j]!='e' && s[j]!='i' && s[j]!='o' && s[j]!='u' &&
                // s[j]!='A' && s[j]!='E' && s[j]!='I' && s[j]!='O' && s[j]!='U'
            if(
               !isVowel(s[j]) 
            ){
                j--;
                continue;
            }
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};