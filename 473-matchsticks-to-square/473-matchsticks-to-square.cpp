class Solution {
public:
    bool makesquare(vector<int>& nums) {
       int n = nums.size(); int k = 4;
        int sum = 0;
        vector<int> dp(1<<16 + 2, -1);
        dp[0] = 0;
        for(auto x: nums) sum += x;
        if(sum % k) return false;
        sum /= k;
        int tar = sum;
        
     for(int mask = 0; mask < (1 << n); mask++){
         if(dp[mask] == -1) continue;  // not desired combination
         for(int i = 0; i < n; i++){
              if(!(mask & (1 << i)) and dp[mask] + nums[i] <= tar){
                dp[mask | (1 << i)] = (dp[mask] + nums[i]) % tar; 
             } 
          }  
        }
        return dp[(1 << n) - 1] == 0;
    }
};