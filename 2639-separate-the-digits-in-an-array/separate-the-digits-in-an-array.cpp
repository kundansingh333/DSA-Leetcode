class Solution {
public:
    vector<int> separate(int &num){
        vector<int>res;

        while(num>0){
            int temp=num%10;
            res.push_back(temp);
            num/=10;
        }

        reverse(res.begin(),res.end());
        return res;
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            vector<int> arr=separate(nums[i]);
            for(int j=0; j<arr.size(); j++){
                ans.push_back(arr[j]);
            }
        }
        return ans;
    }
};