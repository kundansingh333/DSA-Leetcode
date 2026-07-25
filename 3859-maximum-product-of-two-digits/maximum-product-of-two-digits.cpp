class Solution {
public:
    int findMaxEle(int n){
        long long maxDigit=INT_MIN;
        long long secondmaxDigit=INT_MIN;
        while(n){
            int last_digit = n%10;
             if(maxDigit <= last_digit){
                secondmaxDigit = maxDigit;
                maxDigit=last_digit;
             }
            else if((int)secondmaxDigit < last_digit && last_digit < (int)maxDigit){
                 secondmaxDigit = last_digit;
             }
             n=n/10;
        }

        //if(secondmaxDigit==INT_MIN) return maxDigit * maxDigit;
        return secondmaxDigit*maxDigit;
    }
    int maxProduct(int n) {
        return findMaxEle(n);
        // vector<long long>v;
        // while(n){
        //     v.push_back(n%10);
        //     n=n/10;
        // }
        // sort(v.begin(),v.end());
        // return v[v.size()-1] * v[v.size()-2];
    }
};