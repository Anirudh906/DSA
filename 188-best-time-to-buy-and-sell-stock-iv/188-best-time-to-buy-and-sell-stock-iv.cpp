class Solution {
public:
   int solve(vector<int> &prices, int idx, int buy, int cap, vector<vector<vector<int>>> &dp){
        if(idx == prices.size()) return 0;
        if(cap == 0) return 0;
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        if(buy){
            int profit = max(-prices[idx] + solve(prices, idx+1, 1-buy, cap, dp),
                            0 + solve(prices, idx+1, buy, cap, dp));
            dp[idx][buy][cap] = profit;
        }else {
            int profit = max(prices[idx] + solve(prices, idx+1, 1-buy, cap-1, dp),
                            0 + solve(prices,idx+1, buy, cap, dp));
            dp[idx][buy][cap] = profit;
        }
        return dp[idx][buy][cap];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int> (k+1, -1)));
         return solve(prices, 0, 1, k, dp);
    }

};