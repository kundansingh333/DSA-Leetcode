class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // int n=nums.size();
        // vector<int>ans;
        // for(int i=0; i<n; i++){
        //     if(nums[i]<pivot){
        //         ans.push_back(nums[i]);
        //     }
        // }

        // for(int i=0; i<n; i++){
        //     if(nums[i]==pivot){
        //         ans.push_back(nums[i]);
        //     }
        // }

        // for(int i=0; i<n; i++){
        //     if(nums[i]>pivot){
        //         ans.push_back(nums[i]);
        //     }
        // }
        // return ans;

        int n=nums.size();
        int countLess=0;
        int countEqual=0;
        for(auto num:nums){
            if(num<pivot){
                countLess++;
            }else if(num==pivot){
                countEqual++;
            }
        }
        int less_ptr=0;
        int equal_ptr=countLess;
        int great_ptr=countLess+countEqual;
        vector<int>ans(n);
        for(auto num:nums){
            if(num<pivot){
                ans[less_ptr++]=num;
            }else if(num==pivot){
                ans[equal_ptr++]=num;
            }else{
                ans[great_ptr++]=num;
            }
        }
        return ans;
    }
};