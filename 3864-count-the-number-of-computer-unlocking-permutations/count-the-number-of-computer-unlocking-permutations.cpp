class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        long long M=1e9+7;
        int root=complexity[0];
        if(n<=1){
            return 1;
        }
        for(int i=1; i<n; i++){
            if(complexity[i]<=root){
                return 0;
            }
        }
        long long ans=1;
        for(int i=1; i<n; i++){
            ans=(ans*i)%M;
        }
        return ans;
    }
};