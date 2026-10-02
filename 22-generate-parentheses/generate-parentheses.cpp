class Solution {
public:

    vector<string>ans;
    // bool isValid(string curr){
    //     int count=0;
    //     for(auto ch:curr){
    //         if(ch=='('){
    //             count++;
    //         }else{
    //             count--;
    //         }
    //         if(count<0){
    //             return false;
    //         }
    //     }
    //     return count==0;
    // }
    
    void solve(string &curr,int n,int open ,int close){
        if(curr.length()==2*n){
            // if(isValid(curr)){
            //     ans.push_back(curr);
            // }
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            solve(curr,n,open+1,close);
            curr.pop_back();
        }
        
        if(close<open){
            curr.push_back(')');
            solve(curr,n,open,close+1);
            curr.pop_back();
        }
        

    }

    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        string curr = "";
        solve(curr,n,open,close);
        return ans;
    }
};