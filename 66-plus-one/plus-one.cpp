class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // int size=digits.size()-1;
        // for(int i=size; i>=0; i--){
        //     if(digits[i]<9){
        //         digits[i]++;
        //         return digits;
        //     }
        //     digits[i]=0;
        // }
        // digits.inrt(digits.begin(),1);
        // return digits;

        int n=digits.size()-1;
        for(int i=n; i>=0; i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
    
};