class Solution {
public:
    int ans = INT_MAX, mn = INT_MAX;
    
    void solve(vector<int> &tc,int pos, int m, int target, int sum){ 
        if(abs(sum - target) < mn){ 
            mn = abs(sum - target);
            ans = sum;
        }
      
        if(abs(sum - target) == mn) ans = min(ans, sum); 
      
        if(pos >= tc.size() || sum - target > mn) return;
       
         solve(tc, pos + 1, m, target, sum + tc[pos]); 
         solve(tc, pos + 1, m, target, sum + 2 * tc[pos]); 
         solve(tc, pos + 1, m, target, sum); 
        
        
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = baseCosts.size(), m = toppingCosts.size();
      
        for(int i = 0; i < n; i++){
            solve(toppingCosts, 0, m, target, baseCosts[i]);
        }
        return ans;
    }
};