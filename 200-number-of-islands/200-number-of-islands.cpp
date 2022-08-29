class Solution {
public:
int n, m;
vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

bool possible(int x, int y) {
	return (x < n && x >= 0 && y < m && y >= 0);
}
void dfs(int x, int y, vector<vector<char>>& grid, int n, int m) {

	grid[x][y] = '0';
	for (int i = 0; i < 4; i++) {
		int a = x + dx[i]; int b = y + dy[i];
		if (possible(a, b) && grid[a][b] == '1')dfs(a, b, grid, n, m);
	}
}
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
         m = grid[0].size();
        int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '1') {
				dfs(i, j, grid, n, m);
				res++;
			}
		}
	} return res;
    }
};