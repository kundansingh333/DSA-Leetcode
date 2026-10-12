class Solution {
public:
    bool fun(int a){
        while(a>0){
            int rem=a%10;
            if(rem==0) return false;
            a/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a=0;
        int b=0;
        for(int i=1; i<=n; i++){
            a=n-i;
            
            if(fun(a) && fun(i)){
                return {a,i};
            }
        }
        return {};
    }
};