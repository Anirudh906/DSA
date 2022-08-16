class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<pair<int, int>>> vp(2005);
        int n = workers.size(), m = bikes.size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
            int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                vp[d].push_back({i, j});    
            }
        }
        
        vector<int> res(n, -1);
        vector<int> vis(m);
        for(int i = 0; i <= 2001; i++){
            for(int j = 0; j < vp[i].size(); j++){
                if(res[vp[i][j].first] == -1 and !vis[vp[i][j].second]){
                    vis[vp[i][j].second] = true;
                    res[vp[i][j].first] = vp[i][j].second;
                }
            }
        }
        return res;
    }
};