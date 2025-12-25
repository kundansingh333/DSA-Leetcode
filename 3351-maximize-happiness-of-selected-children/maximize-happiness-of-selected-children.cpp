class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n= happiness.size()-1;
        sort(happiness.begin(),happiness.end());

        long long sum=0;
        int decrement=0;

        int i=n;
        while(k>0){
            int num=happiness[i]-decrement;
            if(num>0){
                sum+=num;
            }else{
                sum+=0;
            }
            k--;
            i--;
            decrement++;
        }
            
            

        return sum;
    }
};