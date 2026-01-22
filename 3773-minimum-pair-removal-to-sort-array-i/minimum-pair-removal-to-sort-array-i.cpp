class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        // int count=0;
        // for(int i=nums.size()-1; i>=2; i--){
        //     int a=nums[i]+nums[i-1];
        //     int b=nums[i-1]+nums[i-2];
        //     if(a<=b){
        //         nums.pop_back();
        //         nums[i-1]=a;
        //         count++;
        //     }
        // }
        // return count;
        int operations=0;
        while(true){
            bool isSorted=true;
            for(size_t i=0; i<nums.size()-1; i++){
                if(nums[i]>nums[i+1]){
                    isSorted=false;
                    break;
                }
            }
            if(isSorted) return operations;

            long long minSum=LLONG_MAX;
            int minIndex=-1;
            for(size_t i=0; i<nums.size()-1; i++){
                long long currentSum=(long long)nums[i]+nums[i+1];
                if(currentSum<minSum){
                    minSum=currentSum;
                    minIndex=i;
                }
                
            }
            
            nums[minIndex]=(int)minSum;
            nums.erase(nums.begin()+minIndex+1);
            operations++;
        }
        return 0;
    }
};