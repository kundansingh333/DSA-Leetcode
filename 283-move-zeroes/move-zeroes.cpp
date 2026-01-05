class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> n_nums;
        int count =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                n_nums.push_back(nums[i]);
            }else{
                count++;
            }
        }
        for(int i=n_nums.size(); i<nums.size(); i++){
            n_nums.push_back(0);
        }
        nums=n_nums; 
    }
};