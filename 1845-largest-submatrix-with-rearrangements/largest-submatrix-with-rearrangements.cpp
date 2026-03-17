class Solution {
public:
    
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int maxi=0;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i>0 && matrix[i][j]!=0){
                    matrix[i][j]+=matrix[i-1][j];

                }
            }
            vector<int> current_row=matrix[i];
            sort(current_row.begin(),current_row.end(),greater<int>());

            for(int k=0;k<col; k++){
                int current_area=current_row[k]*(k+1);
                maxi=max(current_area,maxi);
            }
        }
        return maxi;
    }
};