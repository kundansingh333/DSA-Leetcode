class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        // vector<int>ans;
        // for(int i=0; i<nums.size(); i++){
        //     nums[i]=nums[i]*nums[i];
        // }
        // sort(nums.begin(),nums.end());
        // return nums;



        int n = nums.size();
        vector<int> neg;
        vector<int> pos;
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
            }

        }
        reverse(neg.begin(),neg.end());
        for(int i=0; i<neg.size(); i++){
            neg[i]=neg[i]*neg[i];

        }
        for(int i=0; i<pos.size(); i++){
            pos[i]=pos[i]*pos[i];
            
        }


        int i=0;
        int j=0;
        int idx=0;
        while(i<neg.size() && j<pos.size()){
            if(neg[i]<=pos[j]){
                // ans.push_back(neg[i]);
                nums[idx]=neg[i];
                i++;
                idx++;
            }else{
                // ans.push_back(pos[j]);
                nums[idx]=pos[j];
                j++;
                idx++;
            }
        }
       
        while(i<neg.size()){
        //    ans.push_back(neg[i]);
            nums[idx]=neg[i];
                i++;
                idx++;

        }
        while(j<pos.size()){
            // ans.push_back(pos[j]);
            nums[idx]=pos[j];
                j++;
                idx++;
        }
        return nums;

        
        

        
    }
};