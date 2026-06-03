class Solution {
private:
    struct Ride {
        int start;
        int duration;
        int sum;
    };

    int solveOneOrder(const vector<int>& startA, const vector<int>& durationA,
                      const vector<int>& startB, const vector<int>& durationB) {
        
        int n = startA.size();
        int m = startB.size();
        
        vector<Ride> ridesB(m);
        for (int j = 0; j < m; j++) {
            ridesB[j] = {startB[j], durationB[j], startB[j] + durationB[j]};
        }
        
        // Sort Ride B by start times ascending
        sort(ridesB.begin(), ridesB.end(), [](const Ride& x, const Ride& y) {
            return x.start < y.start;
        });
        
        // Prefix minimum of duration (For Case A)
        vector<int> prefMinDuration(m);
        prefMinDuration[0] = ridesB[0].duration;
        for (int j = 1; j < m; j++) {
            prefMinDuration[j] = min(prefMinDuration[j - 1], ridesB[j].duration);
        }
        
        // Suffix minimum of start + duration (For Case B)
        vector<int> suffMinSum(m);
        suffMinSum[m - 1] = ridesB[m - 1].sum;
        for (int j = m - 2; j >= 0; j--) {
            suffMinSum[j] = min(suffMinSum[j + 1], ridesB[j].sum);
        }
        
        int bestFinish = INT_MAX;
        
        // Evaluate each ride from category A
        for (int i = 0; i < n; i++) {
            int finishA = startA[i] + durationA[i];
            
            // Binary search for the first ride B that opens STRICTLY AFTER finishA
            int low = 0, high = m - 1, splitIdx = m;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (ridesB[mid].start > finishA) {
                    splitIdx = mid;
                    high = mid - 1; // Look left for an even earlier one
                } else {
                    low = mid + 1;
                }
            }
            
            // Case A: Ride B opens <= finishA (Indices from 0 to splitIdx - 1)
            if (splitIdx > 0) {
                bestFinish = min(bestFinish, finishA + prefMinDuration[splitIdx - 1]);
            }
            
            // Case B: Ride B opens > finishA (Indices from splitIdx to m - 1)
            if (splitIdx < m) {
                bestFinish = min(bestFinish, suffMinSum[splitIdx]);
            }
        }
        
        return bestFinish;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        // Option 1: Land Ride First -> Water Ride Second
        int ans1 = solveOneOrder(landStartTime, landDuration, waterStartTime, waterDuration);
        
        // Option 2: Water Ride First -> Land Ride Second
        int ans2 = solveOneOrder(waterStartTime, waterDuration, landStartTime, landDuration);
        
        return min(ans1, ans2);
    }
};