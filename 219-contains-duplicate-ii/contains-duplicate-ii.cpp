class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // for(int i=0; i<nums.size()-1; i++){
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[i]==nums[j] && abs(i-j)<=k){
        //             return true;
        //         }
        //     }
        // }
        // return false;


        unordered_set<int> window;
        
        for (int i = 0; i < nums.size(); i++) {
            // 1. Check if the element already exists in the current window
            if (window.count(nums[i])) {
                return true;
            }
            
            // 2. Add the current element to the window
            window.insert(nums[i]);
            
            // 3. If window size exceeds k, remove the oldest element
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};