class Solution {
public:
    vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
 

void dfs(int x, int y, vector<vector<int>> &grid, int m, int n, int &res) {
    res++;
	grid[x][y] = 0; 
	for (int i = 0; i < 4; i++) {
		int a = x + dx[i]; int b = y + dy[i];
		if ((a < m && a >= 0 && b < n && b >= 0) && grid[a][b] == 1)dfs(a, b, grid, m, n, res);
	}
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
      int m = grid.size(); int n = grid[0].size();
      int res = 0;  
      int ans = 0;
	for (int i = 0; i < m; i++) {
        
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1) {
				res = 0;
                dfs(i, j, grid, m, n, res);
				
                ans = max(ans, res);
			}
		}
    }
     return ans;   
    }
};





