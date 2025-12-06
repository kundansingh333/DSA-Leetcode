class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n= nums.size();
        int M=1e9+7;

        vector<int>dp(n+1,0);
        dp[0]=1;
        vector<int> prefix_dp(n+1,0);
        prefix_dp[0]=1;

        deque<int>maxQ;
        deque<int>minQ;

        int left=0;

        for(int i=0; i<n; i++){
            while(!maxQ.empty() && nums[maxQ.back()]<=nums[i]){
                maxQ.pop_back();
            }
            maxQ.push_back(i);

            while(!minQ.empty() && nums[minQ.back()]>=nums[i]){
                minQ.pop_back();
            }
            minQ.push_back(i);

            while(nums[maxQ.front()]-nums[minQ.front()]>k){
                if(left==maxQ.front()) maxQ.pop_front();
                if(left==minQ.front()) minQ.pop_front();
                left++;
            }

            long long current_ways;

            if(left==0){
                current_ways=prefix_dp[i];

            }else{
                current_ways=(prefix_dp[i]-prefix_dp[left-1]+M)%M;
            }
            dp[i+1]=current_ways;
            prefix_dp[i+1]=(prefix_dp[i]+dp[i+1])%M;

        }
        return dp[n];

    }
};