class Solution {
public:
    
    long long solve(int n,vector<long long>&arr,string &ans){
        string s=to_string(n);
        for(int i=0; i<s.length(); i++){
            if(s[i]!='0'){
                ans+=s[i];
                long long n=s[i]-'0';
                arr.push_back(n);
            }
        }
        if(ans.empty()) return 0;
        return stoll(ans);
    }
    long long sumAndMultiply(int n) {
        vector<long long>arr;
        string ans="";
        long long num = solve(n,arr,ans);
        long long sum=0;
        for(auto it:arr){
            sum+=it;
        }
        
        return num*sum;
    }
};