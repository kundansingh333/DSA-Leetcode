class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            int loop=sqrt(nums[i]);
            int count=0;
            int c_sum=0;
            for(int j=1; j<=loop; j++){
                if(nums[i]%j==0){
                    int small_factor=j;
                    int large_factor=nums[i]/j;
                    if(small_factor!=large_factor){
                        count+=2;
                        c_sum+=small_factor+large_factor;
                    }else{
                        count+=1;
                        c_sum+=small_factor;
                    }
                }
                
            }
            if(count==4){
                sum+=c_sum;
            }
            
        }
        return sum;
    }
};