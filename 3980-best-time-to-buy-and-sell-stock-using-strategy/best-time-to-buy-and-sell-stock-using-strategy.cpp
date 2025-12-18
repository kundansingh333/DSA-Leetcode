class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long> p_profit(n+1,0);
        vector<long long > p_prices(n+1,0);


        for(int i=0; i<n; i++){
            p_profit[i+1]=p_profit[i]+(long long)prices[i]*strategy[i];
            p_prices[i+1]=p_prices[i]+prices[i];
        }

        long long total_base_profit=p_profit[n];
        long long max_gain=0;
        for(int i=0; i<=n-k; i++){
            long long current_window_profit=p_profit[i+k]-p_profit[i];
            int mid_index=i+(k/2);
            long long new_window_profit=p_prices[i+k]-p_prices[mid_index];
            
            long long gain=new_window_profit-current_window_profit;
            max_gain=max(max_gain,gain);
        }



        return total_base_profit+max_gain;
    }
};