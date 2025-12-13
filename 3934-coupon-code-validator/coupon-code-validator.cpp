class Solution {
public:
    bool isValidCode(string s){
        if (s.empty()) return false;
        return all_of(
            s.begin(),s.end(),[](char c)
            {
            return(
                c>='A' && c<='Z')||
                (c>='a' && c<='z')||
                (c>='0' && c<='9')||
                (c=='_');
        });
    }
    bool isValidBusiness(string s) {
        return (
            s == "electronics" || 
            s == "grocery" || 
            s == "pharmacy" || 
            s == "restaurant");
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<string>output;
        vector<pair<string,string>>validItems;
        int n=code.size();
        // sort(businessLine.begin(),businessLine.end());
        // sort(code.begin(),code.end());
        for(int i=0; i<n; i++){
            if(isActive[i] && isValidBusiness(businessLine[i])&& isValidCode(code[i])){
                validItems.push_back({businessLine[i],code[i]});
            }
        }
        sort(validItems.begin(),validItems.end());
        for(auto it:validItems){
            output.push_back(it.second);
        }
        return output;

    }
};