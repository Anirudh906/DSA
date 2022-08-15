class Solution {
public:
    // n: no of floors, k: no of eggs
    int superEggDrop(int e, int f) {
        vector<vector<int>> dp(f+1, vector<int> (e+1));
       
        for(int i = 1; i <= e; i++){
            dp[0][i] = 0; dp[1][i] = 1;
        }
         for(int i = 1; i <= f; i++){
            dp[i][1] = i; dp[i][0] = 0;
        }
        for(int i = 2; i <= f; i++){
            for(int j = 2; j <= e; j++){
                dp[i][j] = INT_MAX;
                 int l = 1, r = i, ans = INT_MAX, temp = 0;
                while(l <= r){
                    int m = l + (r - l)/2;
                     int left = dp[m - 1][j - 1]; 
                    int right = dp[i - m][j]; 
                    temp = 1 + max(left, right);          
                    if(left < right){                  
                      l = m + 1;                      
                    }
                    else {    
                       r = m - 1;
                    }
                    ans = min(ans, temp);               
                 }
                 dp[i][j] = ans;
                
            }
      }
    
     return dp[f][e];   
   }
};