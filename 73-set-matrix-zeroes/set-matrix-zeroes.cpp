class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // vector<vector<int>>ans=matrix;
        // int m=matrix.size();
        // int n=matrix[0].size();
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(matrix[i][j]==0){
        //             for(int k=0; k<n; k++){
        //                     ans[i][k]=0;
        //             }
        //             for(int k=0; k<m; k++){
        //                    ans[k][j]=0; 
        //             }
        //         }
        //     }
        // }
        // matrix=ans;

        int m=matrix.size();
        int n=matrix[0].size();

        vector<int>col(n,0);
        vector<int>row(m,0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(matrix[i][j]==0){
                    col[j]=1;
                    row[i]=1;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(col[j] || row[i]){
                    matrix[i][j]=0;
                }
            }
        }


    }
};