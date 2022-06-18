class Solution {
public:
    int solve(vector<int> &prices, int idx, int buy, vector<vector<int>>&dp){
        if(idx >= prices.size()){
            return 0;
        }
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy){
            int profit = max(-prices[idx] + solve(prices, idx+1, 0, dp), 
                            0 + solve(prices, idx+1, 1, dp));
            dp[idx][buy] = profit;
        }else {
            int profit = max(prices[idx] + solve(prices, idx+2, 1, dp),
                             0 + solve(prices, idx+1, 0, dp));
            dp[idx][buy] = profit;
        }
        return dp[idx][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, 1, dp);
    }
};