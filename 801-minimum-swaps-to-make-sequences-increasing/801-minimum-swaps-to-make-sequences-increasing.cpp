class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp, int i1, int swapped){
        
        if(i1 == nums1.size()){
            return 0;
        }
        if(dp[i1][swapped] != -1) return dp[i1][swapped];
        int prev1 = nums1[i1-1];
        int prev2 = nums2[i1-1];
        
        
        if(swapped){
            swap(prev1, prev2);
        }
       
        int ans = INT_MAX;
        
        
        if(nums1[i1] > prev1 and nums2[i1] > prev2) {
              ans = min(ans, solve(nums1, nums2, dp, i1+1, 0));
        } 
        
        if(nums1[i1] > prev2 and nums2[i1] > prev1) {
              ans = min(ans, 1 + solve(nums1, nums2, dp, i1+1, 1));
        }  
        
        
        return dp[i1][swapped] = ans;
    }
    
    int solve2(vector<int> &nums1, vector<int> &nums2){
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2));
        
        int nxtSwap = 0, nxtNoSwap = 0, curSwap = 0, curNoSwap = 0; 
        for(int i = n-1; i >= 1; i--){
            for(int j = 1; j >= 0; j--){
                   int prev1 = nums1[i-1];
                   int prev2 = nums2[i-1];
                   int ans = INT_MAX;
        
 
                    if(j){
                        swap(prev1, prev2);
                    }
                    if(nums1[i] > prev1 and nums2[i] > prev2) {
                          ans = min(ans, nxtNoSwap);
                    } 
        
                    if(nums1[i] > prev2 and nums2[i] > prev1) {
                          ans = min(ans, 1 + nxtSwap);
                    }  
        
               if(j) curSwap = ans;
               else curNoSwap = ans;
        
            }
            nxtNoSwap = curNoSwap;
            nxtSwap = curSwap;
        }
        return min(nxtSwap, nxtNoSwap);
    }
   
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
       // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve2(nums1, nums2);
    }
};