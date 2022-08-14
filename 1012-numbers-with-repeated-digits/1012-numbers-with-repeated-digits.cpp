class Solution {
public:
    int dp[11][2][1024]; //pos, tight, mask
     
    int solve(string &s, int tight, int pos, int mask){
        if(pos == s.size()){
            if(mask != 0) return 1;
            return 0;
        }
        if(dp[pos][tight][mask] != -1) return dp[pos][tight][mask];
        
        
        int ans = 0;
        
            for(int i = 0; i <= (tight ? s[pos] - '0' : 9); i++){
                if(mask & (1 << i)) continue;
                int newMask = (i == 0 and mask == 0 ? 0 : (mask | (1 << i)));
                ans += solve(s, tight & (i == s[pos] - '0'), pos+1, newMask);
            }
        
        return dp[pos][tight][mask] = ans;
    }
    int numDupDigitsAtMostN(int n) {
     string s = to_string(n);
      memset(dp, -1, sizeof dp);
        
      return n - solve(s, 1, 0, 0);
    }
};