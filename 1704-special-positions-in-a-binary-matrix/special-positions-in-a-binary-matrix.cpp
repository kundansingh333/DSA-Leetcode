class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                bool isSpecial=true;

                if(mat[i][j]==1){
                    for(int k=0; k<n; k++){
                        if( j!=k && mat[i][k]==1){
                            isSpecial=false;
                            break;
                        }

                    }
                    int l;
                    for(int l=0; l<m; l++){
                        if( l!=i && mat[l][j]==1){
                            isSpecial=false;
                            break;
                        }

                    }
                    if(isSpecial){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};