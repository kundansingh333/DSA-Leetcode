class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        int mini=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0; i<arr.size()-1; i++){
            int current_mini=arr[i+1]-arr[i];
            mini=min(current_mini,mini);
        }
        for(int i=0; i<arr.size()-1;i++){
            // vector<int>c_ans;

            if(arr[i+1]-arr[i]==mini){
                ans.push_back({arr[i],arr[i+1]});
            }   
        }
        return ans;
    }
};