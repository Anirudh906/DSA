// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int solve(vector<vector<int>> &dp, string &s, string &t, int n, int m){
        if(n == 0) return 505;
        if(m == 0) return 1;
        if(dp[n][m] != -1) return dp[n][m];
        int c = s[n-1]; int j;
        for(j = m-1; j >= 0; j--){
            if(c == t[j]) break;
        }
        int ans = 505;
        if(j == -1){
            ans = 1;
        }else {
            ans = min({ans, solve(dp, s, t, n-1, m), 1 + solve(dp, s, t, n-1, j)});
        }
        return dp[n][m] = ans;
    }
    int shortestUnSub(string s, string t) {
        // code here
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans = solve(dp, s, t, n, m);
        return ans == 505 ? -1 : ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends