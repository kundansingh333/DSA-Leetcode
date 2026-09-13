class Solution {
public:
    int countMaximum(vector<vector<int>>&A,vector<vector<int>>&B,int row_offset,int col_offset){
        int n=A.size();
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int B_i=i+row_offset;
                int B_j=j+col_offset;
                if(B_i<0 || B_i>=n || B_j<0 || B_j>=n) continue;
                if(A[i][j]==1 && B[B_i][B_j]==1) count++;
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int maxi=0;
        for(int row_offset=-n+1; row_offset<n; row_offset++){
            for(int col_offset=-n+1; col_offset<n; col_offset++){
                int count=countMaximum(img1,img2,row_offset,col_offset);
                maxi=max(maxi,count);
                // maxi=max(maxi,countMaximum(img1,img2,row_offset,col_offset));
            }
        }
        return maxi;
    }
};