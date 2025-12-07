class Solution {
public:
    int countOdds(int low, int high) {
        // int count=0;
        // for(int i=low; i<=high; i++){
        //     if(i%2!=0){
        //         count++;
        //     }
        // }
        // return count;

        // int N=high-low+1;
        // if(N%2==0){
        //     return N/2;
        // }else{
        //     int n=N/2;
        //     if(low%2!=0){
        //         return n+1;
        //     }else{
        //         return n;
        //     }
        // }
        // return 0;
        return (high+1)/2-low/2;

    }
};