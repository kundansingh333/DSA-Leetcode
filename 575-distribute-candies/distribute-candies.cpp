class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int>s;
        int count=candyType.size()/2;
        for(auto it:candyType){
            s.insert(it);
        }
        int n=s.size();
        return min(n,count);


    }
};