class Solution {
public:

    bool uniformArray(vector<int>& nums1) {
        int sm_odd_number=INT_MAX;
        for(auto num:nums1){
            if(num%2!=0){
                sm_odd_number=min(sm_odd_number,num);
            }
        }
        for(auto num:nums1){
            if(num%2==0 && sm_odd_number!=INT_MAX && num<sm_odd_number){
                return false;
            }
        }
        return true;
    }
};