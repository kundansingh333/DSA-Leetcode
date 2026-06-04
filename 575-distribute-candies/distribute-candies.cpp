class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int>s(candyType.begin(),candyType.end());
        int count=candyType.size()/2;
        // for(auto it:candyType){
        //     s.insert(it);
        // }
        int n=s.size();
        return min(n,count);


    }
};