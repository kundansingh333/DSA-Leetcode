class Solution {
public:
    long double getAreaBelow(long double y,vector<vector<int>>&squares){
        long double currentArea=0;
        for(const auto& sq:squares){
            long double bottom=sq[1];
            long double side=sq[2];
            long double top=bottom+side;
            if(bottom>=y){
                continue;
            }else if(top<=y){
                currentArea+=(side*side);
            }else{
                long double bottomSide=y-bottom;
                currentArea+=(side*bottomSide);
            }
        }
        return currentArea;
    }

    double separateSquares(vector<vector<int>>& squares) {
        long double totalArea=0;
        long double minY=2e9;
        long double maxY=0;

        for(const auto& sq:squares){
            totalArea+=(long double)sq[2]*sq[2];
            minY=min(minY,(long double)sq[1]);
            maxY=max(maxY,(long double)sq[1]+sq[2]);
        }

        long double target=totalArea/2.0;
        long double low=minY;
        long double high=maxY;

        for(int i=0; i<60; i++){
            long double mid=low+(high-low)/2;
            if(getAreaBelow(mid,squares)<target){
                low=mid;
            }else{
                high=mid;
            }
        }
        return (double)high;

    }
};