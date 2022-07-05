class Solution {
public:
    int t = 0;
    void solve(int u, vector<bool>& vis, vector<int>& disc, vector<int>& low,     vector<int>& parent, vector<vector<int>>& g, vector<vector<int>>& res) {
        
        vis[u] = true;
        disc[u] = low[u] = t++;
        for (int v : g[u]) {
            if (!vis[v]) {
                parent[v] = u;
                solve(v, vis, disc, low, parent, g, res);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    res.push_back({u, v});
                }

            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }

        }
    } 
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<bool> vis(n, false);
        vector<int> disc(n, 0), low(n, 0), parent(n, -1);
        vector<vector<int>> g(n), res;
        for (auto & p : connections) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            solve(i, vis, disc, low, parent, g, res);
        }
        return res;
    }
};