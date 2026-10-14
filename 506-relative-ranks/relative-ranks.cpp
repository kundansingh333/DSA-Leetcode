class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> scoreWithIndex(n);
        for (int i = 0; i < n; ++i) {
            scoreWithIndex[i] = {score[i], i};
        }

        // Sort descending by score
        sort(scoreWithIndex.rbegin(), scoreWithIndex.rend());

        vector<string> result(n);
        const vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        for (int rank = 0; rank < n; ++rank) {
            int originalIndex = scoreWithIndex[rank].second;
            if (rank < 3) {
                result[originalIndex] = medals[rank];
            } else {
                result[originalIndex] = to_string(rank + 1);
            }
        }

        return result;
    }
};