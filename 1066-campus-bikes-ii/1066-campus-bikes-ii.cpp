class Solution {
public:
    int solve(vector<vector<int>> &workers, vector<vector<int>> &bikes, vector<vector<int>> &dp, int idx, int bits){
        if(idx == workers.size()){
            return 0;
        }
        if(dp[idx][bits] != -1) return dp[idx][bits];
        int best = INT_MAX;
        for(int j = 0; j < bikes.size(); j++){
            if(bits & (1 << j)) continue;
            int dis = abs(workers[idx][0] - bikes[j][0]) + abs(workers[idx][1] - bikes[j][1]);
            best = min(best, dis + solve(workers, bikes, dp, idx+1, bits|(1<<j)));
        }
        return dp[idx][bits] = best;
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size();
        int m = bikes.size();
        
       vector<vector<int>> dp(n+1, vector<int>(1<<m + 1, -1));
        
        return solve(workers, bikes, dp, 0, 0);
    }
};