class Solution {
public:
    int sze(int x) { 
        return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3;
    }
    int solve(int l, int k, string &s, vector<vector<int>> &dp){
        if(k < 0) return 150;
        int n = s.length();
        if(l >= n || n-l <= k) return 0;
        int &temp = dp[l][k];
        if(temp != -1) return temp;
        vector<int> cnt(26);
        temp = n;
        for(int i = l, mx = 0; i < n; i++){
            mx = max(mx, ++cnt[s[i] - 'a']);
            temp = min(temp, 1 + sze(mx) + solve(i+1, k-(i-l+1-mx), s, dp));
        }
        return temp;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> dp(150, vector<int> (150, -1));

        return solve(0, k, s, dp);
        
    }
};


