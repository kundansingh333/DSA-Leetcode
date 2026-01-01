class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=INT_MIN;
        int n=candies.size();
        vector<bool> result;

        for(int i=0; i<n;i++){
            maxi=max(maxi,candies[i]);
        }

        for(int i=0; i<n; i++){
            int sum=candies[i]+extraCandies;
            if(sum>=maxi){
                result.push_back(true);
            }else{
                result.push_back(false);
            }
        }
        return result;

    }
};