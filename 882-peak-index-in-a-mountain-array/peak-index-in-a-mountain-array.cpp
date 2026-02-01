class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // int maxi=INT_MIN;
        // int index=-1;
        // for(int i=0; i<arr.size(); i++){
        //     maxi=max(arr[i],maxi);
        //     if(maxi==arr[i]){
        //         index=i;
        //     }
        // }
        // return index;

       

        int low=0;
        int high=arr.size()-1;
        int res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<arr[mid+1]){
                low=mid+1;
            }else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
};