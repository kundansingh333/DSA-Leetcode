class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int maxi=INT_MIN;
        int index=-1;
        for(int i=0; i<arr.size(); i++){
            maxi=max(arr[i],maxi);
            if(maxi==arr[i]){
                index=i;
            }
        }
        return index;
    }
};