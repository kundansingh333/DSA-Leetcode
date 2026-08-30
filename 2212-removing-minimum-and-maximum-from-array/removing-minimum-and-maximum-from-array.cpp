class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();

        int mini=min_element(nums.begin(),nums.end()) - nums.begin();
        int maxi=max_element(nums.begin(),nums.end()) - nums.begin();

        int left=min(maxi,mini);
        int right=max(maxi,mini);

        int fromLeft=right+1;
        int fromRight=n-left;
        int fromMiddle=(left+1)+(n-right);

        return min({fromLeft,fromRight,fromMiddle});

        
        
    }
};