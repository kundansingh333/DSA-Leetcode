class Solution {
public:
    vector<vector<int>>t=vector<vector<int>>(101,vector<int>(10001,-1));
    int solve(int k,int n){
        if(n==0 || n==1){
            return n;
        }
        if(k==1){
            return n;
        }
        if(t[k][n]!=-1){
            return t[k][n];
        }
        int mn=INT_MAX;
        // for(int x=1; x<=n; x++){
        //     // int temp_ans=1+max(solve(k-1,x-1),solve(k,n-x));
        //     int low,high;
        //     if(t[k-1][x-1]!=-1){
        //         low=t[k-1][x-1];
        //     }else{
        //         low=solve(k-1,x-1);
        //         t[k-1][x-1]=low;
        //     }


        //     if(t[k][n-x]!=-1){
        //         high=t[k][n-x];
        //     }else{
        //         high=solve(k,n-x);
        //         t[k][n-x]=high;
        //     }
        //     int temp_ans=1+max(low,high);


        //     mn=min(mn,temp_ans);
        // }


        int low = 1, high = n;
 
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            int left = solve(k - 1, mid - 1); // Egg breaks
            int right = solve(k, n - mid);    // Egg survives
            
            int temp_ans = 1 + max(left, right);
            mn = min(mn, temp_ans);
            
            if(left < right){
                low = mid + 1;
            } 
            
            else {
                high = mid - 1;
            }
        }
        return t[k][n] = mn;
    }
    int superEggDrop(int k, int n) {
        return solve(k,n);
    }
};