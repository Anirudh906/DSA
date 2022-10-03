class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int ans = 0;
        int sum = 0, mx = 0;
        for(int i = 0; i < n; i++){
            if(i > 0 and colors[i] != colors[i-1]){
                ans += sum - mx;
                sum = 0; mx = 0;
            }
            
                sum += neededTime[i];
                mx = max(mx, neededTime[i]);
        
        }
        ans += sum - mx;
        return ans;
    }
};