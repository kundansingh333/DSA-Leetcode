class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        int running_sum = 0;
        for (int i = 0; i <= 100; i++) {
            int temp = count[i];
            count[i] = running_sum;
            running_sum += temp;
        }
        

        vector<int> result;
        result.reserve(nums.size());
        for (int num : nums) {
            result.push_back(count[num]);
        }
        
        return result;

    }
};