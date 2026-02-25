class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        for(int i=0; i<arr.size()-1; i++){
            for(int j=i+1; j<arr.size(); j++){
                int bits1=__builtin_popcount(arr[i]);
                int bits2=__builtin_popcount(arr[j]);
                if(bits1>bits2){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
                if(bits1==bits2){
                    if(arr[i]>arr[j]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
                    
                }

            }
            

        }
        return arr;
    }
};