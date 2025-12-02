class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long M=1e9+7;
        unordered_map<int,int> y_count;
        for(const auto& point:points){
            y_count[point[1]]++;
        }
        long long total_trapezpids=0;
        long long running_sum_segments=0;
        for(auto const& [y, count]:y_count){
            if(count<2) continue;
            long long current_segments=(1LL*count*(count-1))/2;
            long long new_trapezoids=(current_segments%M * running_sum_segments%M)%M;
            total_trapezpids=(total_trapezpids+new_trapezoids)%M;
            running_sum_segments=(running_sum_segments+current_segments)%M;


        }
        return total_trapezpids;
    }
};