class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int size=nums.size();
        vector<bool> isDivisible;
        // for(int i=0; i<size; i++){
        //     int n=i+1;
        //     int number=0;
        //     int count=n;
        //     while(n>0){
                
        //         if(nums[n-1]==1){
        //             int p=count-n;
        //             int a=pow(2,p);
        //             number+=a;
        //         }

        //         n--;
        //     }
        //     if(number%5==0){
        //         isDivisible.push_back(true);
        //     }else{
        //         isDivisible.push_back(false);
        //     }
            
        // }
        // return isDivisible;

        int remainder=0;
        for(int bit: nums){
            remainder=(remainder*2+bit)%5;
            isDivisible.push_back(remainder==0);
        }
        return isDivisible;
    }
};