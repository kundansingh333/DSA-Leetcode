class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target){
            return true;
        }
        int m=mat.size();
        int n= mat[0].size();
        vector<vector<int>>transposed(n,vector<int>(m,0));
        int count=0;
        while(count<3){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    transposed[i][j]=mat[j][i];
                }
                reverse(transposed[i].begin(),transposed[i].end());
            }
            mat=transposed;
            
            if(transposed==target){
                return true;
            }else{
                count++;
            }
       
        }
        
        return false;
    }
};