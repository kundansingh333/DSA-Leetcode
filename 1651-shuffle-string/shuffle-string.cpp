class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        // int n=indices.size();
        // int start=0;
        // for(int i=0; i<n; i++){
        //     if(indices[0]==0){
        //         return s;
        //     }
        //     if(indices[i]==0){
        //         start=i;
        //         break;
        //     }
        // }
        // string ans=s.substr(start);
        // ans+=s.substr(0,n-start);
        // return ans;


        int n = s.length();
        string result(n, ' ');
        
        for (int i = 0; i < n; ++i) {
            result[indices[i]] = s[i];
        }
        
        return result;
    }
};