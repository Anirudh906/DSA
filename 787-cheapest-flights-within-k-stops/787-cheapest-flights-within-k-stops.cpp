class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dp(n, 1e9);
        dp[src] = 0;
        
        for(int i = 0; i <= k; i++){
               vector<int> temp = dp;
            for(auto &f: flights){
                  if(temp[f[0]] != INT_MAX) temp[f[1]] = min(temp[f[1]], f[2] + dp[f[0]]);                         
            }
            dp = temp;
        }
        
        return dp[dst] == 1e9 ? -1 : dp[dst];
    }
};