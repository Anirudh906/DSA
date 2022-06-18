class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <=1; buy++){
                if(buy){
                    dp[idx][buy] = max(-prices[idx] + dp[idx+1][1 - buy], 
                                      0 + dp[idx + 1][buy]);
                }else {
                    dp[idx][buy] = max(prices[idx] + dp[idx+1][1-buy],
                                      0 + dp[idx+1][buy]);
                }
            }
        }
        return dp[0][1];
    }
};