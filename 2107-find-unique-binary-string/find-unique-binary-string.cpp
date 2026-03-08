class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int l=nums.size();
        int n=l<<1;
        unordered_map<int,int>mp;
        for(auto it:nums){
            int number=stoi(it,nullptr,2);
            mp[number]++;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(mp.find(i)==mp.end()){
                ans=i;
                break;
            }
        }
        string s=bitset<32>(ans).to_string();
        // s.erase(0,s.find_first_not_of('0'));
        string st=s.substr(32-l);
        return st;
    }
};