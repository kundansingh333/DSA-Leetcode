class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0;
        int j=0;
        string mini_str="";
        string ans="";
        int count=0;
        while(j<s.length()){
            if(s[j]=='1'){
                count++;

            }
            ans+=s[j];
            if(count==k){
                while(count==k){
                    if(mini_str.empty()||mini_str.length()>ans.length()||(ans.length()==mini_str.length()&& ans<mini_str)){
                        mini_str=ans;
                    }
                    if(s[i]=='1') count--;
                    ans.erase(0,1);
                    i++;
                }
            }
            j++;
        }

        return mini_str;
    }
};