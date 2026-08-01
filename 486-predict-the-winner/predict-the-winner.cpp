class Solution {
public:
    int fun(vector<int> &nums,int left,int right){
        if(left==right) return nums[left];
        int leftSide=nums[left]-fun(nums,left+1,right);
        int rightSide=nums[right]-fun(nums,left,right-1);
        return max(leftSide,rightSide);
    }
    bool predictTheWinner(vector<int>& nums) {
        return fun(nums,0,nums.size()-1)>=0;
    }
};