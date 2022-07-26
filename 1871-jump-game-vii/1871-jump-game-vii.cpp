class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        vector<bool> dp(n, false);
        dp[0] = true;
        int c = 0;
        for(int i = 1; i < n; i++){
            if(i > maxJump) c -= dp[i - maxJump - 1];
            if(i >= minJump) c += dp[i - minJump];
            
            if(c > 0 and s[i] == '0')dp[i] = true;
            
        }
        return dp.back();
    }
};