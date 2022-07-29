class Solution {
public:
    int memo[50001];
    
//     int solve(vector<int> &startTime, vector<vector<int>> &jobs, int n, int pos){
//         if(pos == n){
//             return 0;
//         }
//         if(memo[pos] != -1) return memo[pos];
//         int nextIdx = lower_bound(startTime.begin(), startTime.end(), jobs[pos][1]) - startTime.begin();
        
//         int maxProfit = max(solve(startTime, jobs, n, pos + 1), 
//                             jobs[pos][2] + solve(startTime, jobs, n, nextIdx));
        
//         return memo[pos] = maxProfit;
//     }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = profit.size();
        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        for(int i = 0; i < n; i++){
            startTime[i] = jobs[i][0];
        }
        memset(memo, -1, sizeof memo);
    
        
       // return solve(startTime, jobs, n, 0);
        
        
        memo[n] = 0;
        
        for(int p = n - 1; p >= 0; p--){
            int idx = lower_bound(startTime.begin(), startTime.end(), jobs[p][1]) - startTime.begin();
            memo[p] = max(p+1 < n ? memo[p + 1]: 0, jobs[p][2] + memo[idx]);
        }
        
        return memo[0];
        
    }
};