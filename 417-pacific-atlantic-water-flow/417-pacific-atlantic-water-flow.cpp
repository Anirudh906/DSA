class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &h, int type){
        vis[i][j] += type;
        for(int k =0 ; k < 4; k++){
            int a = i + dir[k][0];
            int b = j + dir[k][1];
            if(a >= 0 and b >= 0 and a < h.size() and b < h[0].size() and h[a][b] >= h[i][j] and vis[a][b] != 3 and vis[a][b] != type){
                dfs(a, b, vis, h, type);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        vector<vector<int>> res;
        
        int n = h.size(), m = h[0].size();
       
        vector<vector<int>> vis(n, vector<int>(m));
        
        for(int i = 0; i < n; i++){
            if(vis[i][0] != 1 and vis[i][0] != 3){
                dfs(i, 0, vis, h, 1);
            }
        }
        for(int j = 0; j < m; j++){
            if(vis[0][j] != 1 and vis[0][j] != 3){
                dfs(0, j, vis, h, 1);
            }
        }
       for(int i = 0; i < n; i++){
           if(vis[i][m-1] != 2 and vis[i][m-1] != 3){
               dfs(i, m-1, vis, h, 2);
           }
       }
        for(int j = 0; j < m; j++){
            if(vis[n-1][j] != 2 and vis[n-1][j] != 3){
                dfs(n-1, j, vis, h, 2);
            }
        }
        
      
        for(int i =0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 3){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};