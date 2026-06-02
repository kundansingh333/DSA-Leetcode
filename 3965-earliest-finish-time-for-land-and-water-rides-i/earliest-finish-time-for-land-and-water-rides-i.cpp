class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minFinishTime = INT_MAX;

        // Try every combination of land ride i and water ride j
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                // --- Scenario 1: Land Ride (i) first, then Water Ride (j) ---
                int landFinish = landStartTime[i] + landDuration[i];
                int waterStart = max(landFinish, waterStartTime[j]);
                int totalFinish1 = waterStart + waterDuration[j];
                
                // --- Scenario 2: Water Ride (j) first, then Land Ride (i) ---
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landStart = max(waterFinish, landStartTime[i]);
                int totalFinish2 = landStart + landDuration[i];

                // Keep the minimum time found so far
                minFinishTime = min({minFinishTime, totalFinish1, totalFinish2});
            }
        }

        return minFinishTime;
    }
};