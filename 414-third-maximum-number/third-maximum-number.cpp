class Solution {
public:
    int thirdMax(vector<int>& nums) {
       set<int>s(nums.begin(),nums.end());
       vector<int>arr(s.begin(),s.end());
         int n=arr.size()-1;
       if(n>=2){
            return arr[n-2];
       }
       return arr[n];

    }
};