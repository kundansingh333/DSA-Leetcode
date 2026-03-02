class Solution {
public:
    int countSwap(vector<int> zeros){
        int n=zeros.size();

        int count=0;
        // for(int i=n; i>=1; i--){
        //     for(int j=0; j<=i-1; j++){
        //         if(zeros[j]>zeros[j+1]){
        //             swap(zeros[j],zeros[j+1]);
        //             count++;
        //         }
        //     }
        // }

        for(int i=0; i<n; i++){
            int target=n-i-1;
            int j=i;
            while(j<n && zeros[j]<target){
                j++;
            }
            if(j==n){
                return -1;
            }
            while(j>i){
                swap(zeros[j],zeros[j-1]);
                count++;
                j--;
            }
        }
        return count;
    }
    int minSwaps(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size()-1;
        // unordered_map<int,int>mp;
        vector<int>zeros;
        for(int i=0; i<row; i++){
            int zero_count=0;
            for(int j=col; j>=0; j--){
                if(grid[i][j]==0){
                    zero_count++;
                }else{
                    break;
                }
            }
            // if(zero_count !=0){
            //     mp[zero_count]++;
                
            // }
            zeros.push_back(zero_count);
        } 
        int count=countSwap(zeros);
        return count;
    }
};