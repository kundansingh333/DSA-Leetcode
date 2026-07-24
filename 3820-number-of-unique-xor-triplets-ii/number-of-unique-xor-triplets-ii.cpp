class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxVal = 0;
        for (int x : nums) {
            maxVal = max(maxVal, x);
        }
        

        int limit = 1;
        while (limit <= maxVal) {
            limit <<= 1;
        }
        limit <<= 1; 


        vector<bool> pairXor(limit, false);
        for (int a : nums) {
            for (int b : nums) {
                pairXor[a ^ b] = true;
            }
        }


        vector<bool> tripletXor(limit, false);
        for (int ab = 0; ab < limit; ab++) {
            if (pairXor[ab]) {
                for (int c : nums) {
                    tripletXor[ab ^ c] = true;
                }
            }
        }


        int uniqueCount = 0;
        for (bool present : tripletXor) {
            if (present) uniqueCount++;
        }

        return uniqueCount;
    }
};