class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        
        // Tracks if row[i] < row[i+1] is already satisfied by previous columns
        vector<bool> is_sorted(rows - 1, false);
        int deletions = 0;

        // Iterate through each column
        for (int j = 0; j < cols; j++) {
            bool delete_col = false;
            
            // Step 1: Check if we MUST delete this column
            for (int i = 0; i < rows - 1; i++) {
                // If rows are not already sorted, and this column breaks the order
                if (!is_sorted[i] && strs[i][j] > strs[i+1][j]) {
                    delete_col = true;
                    break;
                }
            }

            // Step 2: Handle Deletion or Update
            if (delete_col) {
                deletions++;
            } else {
                // If we keep the column, update the is_sorted status
                for (int i = 0; i < rows - 1; i++) {
                    if (!is_sorted[i] && strs[i][j] < strs[i+1][j]) {
                        is_sorted[i] = true;
                    }
                }
            }
        }
        
        return deletions;
    }
    
};