class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        std::unordered_map<int, int> reservedBitmask;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                reservedBitmask[row] |= (1 << (col - 2));
            }
        }

        const int LEFT_MASK  = 15;
        const int RIGHT_MASK = 240;
        const int MID_MASK   = 60;


        int maxFamilies = (n - reservedBitmask.size()) * 2;

        for (const auto& [row, mask] : reservedBitmask) {
            bool leftFree  = (mask & LEFT_MASK) == 0;
            bool rightFree = (mask & RIGHT_MASK) == 0;
            bool midFree   = (mask & MID_MASK) == 0;

            if (leftFree && rightFree) {
                maxFamilies += 2;
            } else if (leftFree || rightFree || midFree) {
                maxFamilies += 1;
            }
        }

        return maxFamilies;
    }
};