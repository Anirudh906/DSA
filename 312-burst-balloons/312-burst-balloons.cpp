class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        int n = nums.size();
        
        for(int i = 0; i < n-1; i++) dp[i][i+1] = 0;
        for (int len = 2; len < n; ++len){
            for (int left = 0; left + len < n; ++left) {
                int right = left + len;
                for (int k = left+1; k < right; ++k)
                    dp[left][right] = max(dp[left][right],           nums[left]*nums[k]*nums[right] + dp[left][k] + dp[k][right]);
            }
        }
        return dp[0][n-1];
    }
};