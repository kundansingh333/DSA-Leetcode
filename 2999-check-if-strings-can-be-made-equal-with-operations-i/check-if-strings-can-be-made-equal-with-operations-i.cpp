class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int i=0;
        int j=2;
        for(int k=0; k<2; k++){
            if(s1==s2) return true;
            if(s1[i]!=s2[i]){
                swap(s1[i],s1[j]);
            }
            
            i++;
            j++;

        }
        return s1==s2?true:false;
    }
};