class Solution {
public:


int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10; 
            n /= 10;       
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int min_element = INT_MAX;

        for (int num : nums) {
            int current_sum = getDigitSum(num);
            min_element = min(min_element, current_sum);
        }

        return min_element;

    }
};