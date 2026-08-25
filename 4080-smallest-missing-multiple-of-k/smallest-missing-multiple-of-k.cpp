class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>s(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1; i<=n+1; i++){
            if(!s.count(k*i)){
                return k*i;
            }
        }
        return 0;
    }
};