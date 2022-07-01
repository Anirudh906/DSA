class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int> (2, 0)));
        
        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j <=k; j++){
                for(int buy = 0; buy < 2; buy++){
                    if(buy){
                        //buy case
                        dp[i][j][buy] = max(-prices[i] + dp[i+1][j][1-buy],
                                           0 + dp[i+1][j][buy]);
                    } else {
                        //sell case, k reduces here
                        dp[i][j][buy] = max(prices[i] + dp[i+1][j-1][1-buy],
                                           0 + dp[i+1][j][buy]);
                    }
                }
            }
        }
       return dp[0][k][1];
    }
};