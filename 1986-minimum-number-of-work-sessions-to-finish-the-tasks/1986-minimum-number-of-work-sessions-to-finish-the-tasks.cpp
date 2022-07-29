class Solution {
public:
    vector<int> sessions;
    unordered_map<string, int> dp;
   
    string encode(int pos, vector<int> tasks){
        string res = "";
        vector<int> copy = tasks;
        res += to_string(pos) + "$";
        sort(copy.begin(), copy.end());
        
        for(int i =0; i < copy.size(); i++){
              res += to_string(copy[i]) + "$";
        }
    
        return res;
    }
    
    int solve(vector<int>&tasks, int sT, int pos){
        if(pos >= tasks.size()) return 0;
        string key = encode(pos, sessions);
        
        if(dp.find(key) != dp.end()) return dp[key];
        
        sessions.push_back(tasks[pos]);
        int ans = 1 + solve(tasks, sT, pos + 1);
        sessions.pop_back();
        
        for(int i = 0; i < sessions.size(); i++){
            if(sessions[i] + tasks[pos] <= sT){
                sessions[i] += tasks[pos];
                ans = min(ans, solve(tasks, sT, pos + 1));
                sessions[i] -= tasks[pos];
            }
        }
        return dp[key] = ans;
        
        
    }
    
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        sessions.clear();
        return solve(tasks, sessionTime, 0);
    }
};


