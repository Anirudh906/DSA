class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
     int ans = 0;
        vector<int> jumps(n + 1, 0);  
        for(int i = 0; i < ranges.size(); i++){
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            jumps[l] = max(jumps[l], r - l);
        }
//         vector<int> dp(n + 1, INT_MAX);
//         dp[0] = 0;
        
//         for(int i = 1; i <= n; i++){
//             for(int j = 0; j < i; j++){
//                 if(j + jumps[j] >= i and dp[j] != INT_MAX){
//                     dp[i] = min(dp[i], 1 + dp[j]);
//                 }
//             }
//         }
//         for(auto x: dp) cout << x << " "; cout << endl;
//         return dp[n] == INT_MAX ? -1 : dp[n];
         int curEnd = 0, farthest = 0;
        for(int i = 0; i < n; i++){
            farthest = max(farthest, i + jumps[i]);
            if(i == curEnd){
                ans++;
                curEnd = farthest;
            }
        }
        return curEnd == n ? ans : -1;
    
    }
};