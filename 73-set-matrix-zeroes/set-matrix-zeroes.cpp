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






        // int m=matrix.size();
        // int n=matrix[0].size();

        // vector<int>col(n,0);
        // vector<int>row(m,0);
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n;j++){
        //         if(matrix[i][j]==0){
        //             col[j]=1;
        //             row[i]=1;
        //         }
        //     }
        // }
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(col[j] || row[i]){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }

        int m= matrix.size();
        int n=matrix[0].size();
        int col0=1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n ;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0=0;
                    }
                    
                }
            }
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]!=0){
                    if((matrix[0][j]==0 ) || (matrix[i][0]==0 )){
                    matrix[i][j]=0;
                }
                }
                
            }
        }
        if(matrix[0][0]==0){
            for(int i=0; i<n; i++){
                matrix[0][i]=0;
            }
        }
        if(col0==0){
            for(int i=0; i<m; i++){
                matrix[i][0]=0;
            }
        }



    }
};