class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int x=stones.back();
            stones.pop_back();
            int y=stones.back();
            stones.pop_back();

            if(x!=y){
                stones.push_back(x-y);
            }
            
        }
        return stones.empty()?0:stones.back();
    }
};