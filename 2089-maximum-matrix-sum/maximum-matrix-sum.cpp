class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int count=0;
        int zero=0;
        int mini=INT_MAX;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0;j<matrix.size();j++){
                sum+=abs(matrix[i][j]);
                mini=min(mini,abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    count++;
                }
                if(matrix[i][j]==0){
                    zero+=1;
                }
            }
        }
        if(count%2==0 || zero>=1){
            return sum;
        }else{
            int total=mini*2;
            sum-=total;
            return sum;
        }
    }
};