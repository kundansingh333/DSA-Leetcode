class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<int>>result(2);
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());

       
        for(auto num:s1){
            if(s2.find(num)==s2.end()){
                result[0].push_back(num);
            }
        }
        for(auto num:s2){
            if(s1.find(num)==s1.end()){
                result[1].push_back(num);
            }
        }
        
        
        return result;
    }
};