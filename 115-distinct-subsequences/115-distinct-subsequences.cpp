class Solution {
public:
    int numDistinct(string s, string t) {
       int m = s.length();
       int n = t.length();
        
       vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
         
        for(int j =0; j<=m; j++){
            dp[0][j]=1;
        }
 for(int j =1; j<=m; j++){
        for(int i = 1; i<=n; i++){
                if(s[j-1]==t[i-1]){
                    dp[i][j] = (1ll*dp[i-1][j-1]+ 1ll*dp[i][j - 1]);
                }else dp[i][j] =dp[i][j-1];
            }
        }
        return (int)dp[n][m];
        
    }
};