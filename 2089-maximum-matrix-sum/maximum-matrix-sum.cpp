class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // int vertical_nbr={-1,1,0,0};
        // int horizontal_nbr={0,0,-1,1};
        long long sum=0;
        int count=0;
        int zero=0;
        int mini=INT_MAX;
        // vector<int> abs_largest_negative;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0;j<matrix.size();j++){

                sum+=abs(matrix[i][j]);
                mini=min(mini,abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    // abs_largest_negative.push_back(abs(matrix[i][j]));
                    count++;
                }
                if(matrix[i][j]==0){
                    zero+=1;
                }
            }
        }
        if(count%2==0 || zero>=1){
            return sum;
            // return zero;
        }else{
            // if(count==1){
            //     sum-=mini*2;
            //     return sum;
            // }
            // sort(matrix.begin(),matrix.end(),[](const vector<int> &a, const vector<int> &b){
            //     return abs(a[0])<abs(b[0]);
            // });
                
            
            // int total=abs_largest_negative[0]*2;
            int total=mini*2;
            sum-=total;
            return sum;
            // return mini;
            // return zero;
        }
        

        
    }
};