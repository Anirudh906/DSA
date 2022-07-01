class Solution {
public:
    vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0;
        int res = -1;
        queue<vector<int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] > 0) cnt++;
                if(grid[i][j] == 2) q.push({i, j});
                
            }
        }
        while(!q.empty()){
            res++;
            int k = q.size();
            for(int i = 0; i < k; i++){
                 auto cur = q.front();
                 q.pop();
                cnt--;
                for(int j = 0; j < 4; j++){
                    int x = cur[0] + dx[j];
                    int y = cur[1] + dy[j];
                    
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1) continue;
                     grid[x][y] = 2;
                    q.push({x, y});
                }
            } 
        }
        
        if(cnt == 0) return max(0, res);
        return -1;
        
}
};