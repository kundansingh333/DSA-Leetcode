class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char>set(jewels.begin(),jewels.end());
        int count=0;
        for(auto stone:stones){
            if(set.count(stone)){
                count++;
            }
        }
        return count;
    }
};