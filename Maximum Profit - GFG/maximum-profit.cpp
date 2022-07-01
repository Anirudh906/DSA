// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>> 
        dp(N+1, vector<vector<int>>(K+1, vector<int>(2, 0)));
        
        for(int i = N-1; i >= 0; i--){
            for(int j = 1; j <= K; j++){
                for(int buy = 0; buy < 2; buy++){
                    if(buy){
                        dp[i][j][buy] = max(-A[i] + dp[i+1][j][1-buy],
                                        0 + dp[i+1][j][buy]);
                    }else {
                        dp[i][j][buy] = max(A[i] + dp[i+1][j-1][1-buy],
                                        0 + dp[i+1][j][buy]);
                    }
                }
            }
        }
        return dp[0][K][1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends