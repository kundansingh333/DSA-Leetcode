class Solution {
public:
    int maximumSum(vector<int>& arr) {
         
        int result=arr[0];
        int noDelete=arr[0];
        int oneDelete=INT_MIN;

        for(int i=1; i<arr.size(); i++){
            int prevNoDelete=noDelete;
            int prevOneDelete=oneDelete;
            noDelete=max(prevNoDelete+arr[i],arr[i]);
            int v2;
            if(prevOneDelete==INT_MIN){
                v2=arr[i];
            }else{
                v2=prevOneDelete+arr[i];
            }
            oneDelete=max(v2,prevNoDelete);
            result=max(result,max(noDelete,oneDelete));
        }
        
        return result;

    }
};