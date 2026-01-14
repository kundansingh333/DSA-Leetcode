class Solution {
public:
    vector<int> count;  // How many active squares cover this node's range
    vector<double> len; // The total length covered by squares in this node's range
    vector<int> X;      // Compressed X coordinates

    void update(int node, int start, int end, int l, int r, int val) {
        if (l >= r) return;

        // If the update range covers this node completely
        if (start == l && end == r) {
            count[node] += val;
        } else {
            int mid = (start + end) / 2;
            // Recursively update children
            // Important: We map the query range [l, r] to the children's ranges
            update(node * 2, start, mid, l, min(r, mid), val);
            update(node * 2 + 1, mid, end, max(l, mid), r, val);
        }

        // Update the 'len' of this node based on 'count'
        if (count[node] > 0) {
            // If this node is covered by at least one square, its length is the full width
            len[node] = X[end] - X[start];
        } else {
            // If not covered directly, it's the sum of children (if not a leaf)
            if (end - start == 1) {
                len[node] = 0;
            } else {
                len[node] = len[node * 2] + len[node * 2 + 1];
            }
        }
    }

    double separateSquares(vector<vector<int>>& squares) {
        // 1. Coordinate Compression for X
        for (auto& sq : squares) {
            X.push_back(sq[0]);
            X.push_back(sq[0] + sq[2]);
        }
        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());

        // Map X values to indices for easy lookup (optional optimization)
        // But here we can just use lower_bound or raw indices since we iterate X.

        // 2. Create Events: (y, type, x_start, x_end)
        // type: 1 for bottom edge, -1 for top edge
        struct Event {
            int y, type, x1, x2;
            bool operator<(const Event& other) const {
                return y < other.y;
            }
        };
        vector<Event> events;
        for (auto& sq : squares) {
            events.push_back({sq[1], 1, sq[0], sq[0] + sq[2]});
            events.push_back({sq[1] + sq[2], -1, sq[0], sq[0] + sq[2]});
        }
        sort(events.begin(), events.end());

        // 3. Initialize Segment Tree
        int n = X.size();
        if (n == 0) return 0.0;
        
        // Tree size 4*n. 'len' needs to handle double for precision in final calc
        count.assign(4 * n, 0);
        len.assign(4 * n, 0.0);

        // 4. First Pass: Calculate Total Union Area
        double totalArea = 0;
        // We need to re-run or store history to find the split. 
        // Let's store history to avoid re-running the sweep.
        // History stores: {y_coordinate, accumulated_area_up_to_this_y}
        vector<pair<double, double>> history; 
        
        int prevY = events[0].y;

        for (const auto& e : events) {
            // Calculate area added by the strip between prevY and current e.y
            double width = len[1]; // Root of segment tree holds total active width
            double height = e.y - prevY;
            
            if (height > 0) {
                totalArea += width * height;
                history.push_back({(double)e.y, totalArea});
            }

            // Update Segment Tree
            // Find compressed indices for x1 and x2
            int l = lower_bound(X.begin(), X.end(), e.x1) - X.begin();
            int r = lower_bound(X.begin(), X.end(), e.x2) - X.begin();
            update(1, 0, n - 1, l, r, e.type);

            prevY = e.y;
        }

        // 5. Find the Split Line
        double target = totalArea / 2.0;
        double prevArea = 0;
        double prevH = events[0].y; // Starting Y of the geometry

        for (auto& h : history) {
            double currY = h.first;
            double currArea = h.second;
            
            // If the target is within this strip (prevArea < target <= currArea)
            if (currArea >= target) {
                // Determine the width of the union in this strip
                // Area_of_strip = width * (currY - prevH)
                // We know Area_of_strip = currArea - prevArea
                double areaInStrip = currArea - prevArea;
                double stripHeight = currY - prevH;
                
                // If areaInStrip is 0 (width was 0), we just continue (shouldn't happen if target is here)
                if (areaInStrip == 0) return currY; 

                double width = areaInStrip / stripHeight;
                double needed = target - prevArea;
                return prevH + (needed / width);
            }
            
            prevArea = currArea;
            prevH = currY;
        }

        return prevH;
    }
};