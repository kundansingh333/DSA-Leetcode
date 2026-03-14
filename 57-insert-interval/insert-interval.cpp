class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l=0;
        int r=intervals.size()-1;
        // int idx;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(intervals[mid][0]<newInterval[0]){
                l=mid+1;
            }else{
                r=mid-1;
            }
            // idx=mid;
        }
        intervals.insert(intervals.begin()+l,newInterval);

        vector<vector<int>>merg;
        for(auto it:intervals){
            if(merg.empty() || merg.back()[1]<it[0]){
                merg.push_back(it);
            }else{
                merg.back()[1]=max(merg.back()[1],it[1]);
            }
        }
        return merg;

        
    }
    
};