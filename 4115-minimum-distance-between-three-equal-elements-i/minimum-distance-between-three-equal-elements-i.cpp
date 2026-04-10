class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        if(nums.size() < 3){
            return -1;
        }
        
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        
        int global_min_sum = INT_MAX;
        bool found = false;
        
        // Loop through the map to check EVERY valid element
        for(auto pair : mp){
            if(pair.second >= 3){
                found = true;
                int current_el = pair.first;
                
                // 1. Gather indices for this specific element
                vector<int> index;
                for(int i = 0; i < nums.size(); i++){
                    if(nums[i] == current_el){
                        index.push_back(i);
                    }
                }

                // 2. Run the sliding window for this specific element
                for(int i = 0; i + 2 < index.size(); i++){
                    int a = abs(index[i] - index[i+1]);
                    int b = abs(index[i+1] - index[i+2]);
                    int c = abs(index[i+2] - index[i]);
                    
                    global_min_sum = min(global_min_sum, a + b + c);
                }
            }
        }
        
        if(!found){
            return -1;
        }
        
        return global_min_sum;
    
    }
};