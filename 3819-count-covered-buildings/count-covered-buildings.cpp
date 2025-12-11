class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        //horizontal
        unordered_map<int,int> min_y_for_x;
        unordered_map<int,int> max_y_for_x;
        //vertical
        unordered_map<int,int> min_x_for_y;
        unordered_map<int,int> max_x_for_y;

        for(auto &it:buildings){
            int x=it[0];
            int y=it[1];
            //horizontal
            if(min_y_for_x.find(x)==min_y_for_x.end()){
                min_y_for_x[x]=y;
                max_y_for_x[x]=y;
            }else{
                min_y_for_x[x]=min(min_y_for_x[x],y);
                max_y_for_x[x]=max(max_y_for_x[x],y);
            }
            //vertical

            if(min_x_for_y.find(y)==min_x_for_y.end()){
                min_x_for_y[y]=x;
                max_x_for_y[y]=x;
            }else{
                min_x_for_y[y]=min(min_x_for_y[y],x);
                max_x_for_y[y]=max(max_x_for_y[y],x);
            }
        }

        int count=0;
        for(auto &it:buildings){
            int x=it[0];
            int y=it[1];

            bool has_horizontal=(y>min_y_for_x[x] && y<max_y_for_x[x]);
            bool has_vertical=(x>min_x_for_y[y] && x<max_x_for_y[y]);
            if(has_horizontal && has_vertical){
                count++;
            }
        }
        return count;
    }
};