class Solution {
public:
    string longestPalindrome(string s) {
         if (s.length() <= 1) return s;
         int n = s.length();
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int mx = INT_MIN, x, y;
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i == j) dp[i][j] = true;
                else if(s[i] == s[j]){
                    if(j - i == 1) dp[i][j] = true;
                    else{
                      if(i + 1 < n and j - 1 >= 0)  dp[i][j] = dp[i + 1][j - 1];
                    }
                }
             if(j - i >= mx and dp[i][j]){
                            mx = max(mx, j - i);
                            x = i;
                            y = j;
                            
                        } 

            }
        }
        return s.substr(x, y -x + 1);
            

        
        }
};