class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int ,int > mp; //key->rem,value->count
        mp[0]=1;

        int count =0;
        int prefix=0;
        for(int it:nums){
            prefix+=it;
            int rem=prefix%k;
            if(rem<0) rem+=k;
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }
            mp[rem]++;
        }
        return count;


    }
};