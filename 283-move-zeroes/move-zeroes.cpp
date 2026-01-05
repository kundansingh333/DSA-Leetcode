class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // vector<int> n_nums;
        // int count =0;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]!=0){
        //         n_nums.push_back(nums[i]);
        //     }else{
        //         count++;
        //     }
        // }
        // for(int i=n_nums.size(); i<nums.size(); i++){
        //     n_nums.push_back(0);
        // }
        // nums=n_nums; 
        int n=nums.size();
        int j=-1;
        for(int i=0; i<nums.size(); i++){
            if(j<0 && nums[i]==0){
                j=i;
            }
            if(j>=0 && nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};