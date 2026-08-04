class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        

        unordered_set<int>s(nums.begin(),nums.end());


        sort(nums.begin(),nums.end());

        int mini=nums[0];
        int maxi=nums[nums.size()-1];
        vector<int>ans;
        for(int i=mini; i<maxi; i++){
            if(s.find(i)==s.end()){
                ans.push_back(i);
            };
        }

        return ans;
        

    }
};