class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res;
        res.push_back(0);
        for(int i=1; i<=n; i++){
            int ones=0;
            int val=i;
            while(val>0){
                int curr=val&1;
                val>>=1;
                if(curr==1){
                    ones++;
                }
            }
            res.push_back(ones);
        }
        return res;
    }
};