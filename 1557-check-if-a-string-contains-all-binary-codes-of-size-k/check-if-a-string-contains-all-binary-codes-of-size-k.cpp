class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int i=0;
        int j=0;
        // int total=pow(2,k);
        int total=1<<k;
        int len=s.length();
        unordered_set<string> mySet;
        string st="";//
        while(j<len){
            if(mySet.size()==total) return true;
            st+=s[j];//
            if(j-i+1<k){
                j++;
            }else if(j-i+1 ==k){
                mySet.insert(st);
                st.erase(st.begin());
                j++;
                i++;
            }

        }
        return mySet.size()==total?true:false;
    }
};