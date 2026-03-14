class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        // vector<vector<int>>res;
        // for(int i=1; i<intervals.size(); i++){
        //     vector<int>ans(2,0);
        //     if(intervals[i-1][1]>=intervals[i][0]){
        //         ans[0]=intervals[i-1][0];
        //         ans[1]=intervals[i][0];
        //         res.push_back({ans[0],ans[1]});
        //     }else{
        //         res.push_back(intervals[i-1]);
        //     }
        // }
        // return res;
        vector<vector<int>>merged;
        for(auto interval:intervals){
            if(merged.empty() || merged.back()[1]<interval[0]){
                merged.push_back(interval);
            }else{
                merged.back()[1]=max(merged.back()[1],interval[1]);
            }
        }
        return merged;

    }
};