class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int count=0;
        int n=cost.size();
        int s_price=0;
        for(int i=n-1; i>=0; i--){
            if(count<2){
                s_price+=cost[i];
                count++;
            }else{
                count=0;
                continue;
            }
        }
        return s_price;
    }
};