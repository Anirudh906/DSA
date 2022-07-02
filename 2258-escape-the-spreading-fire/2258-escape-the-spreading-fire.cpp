class Solution {
public:
    vector<vector<int>> fireTime;
    vector<vector<int>> dis;
    int inf = 1e9;
    vector<vector<int>> dir={{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    void spreadFire(vector<vector<int>> &grid, int &n, int &m){
    
    
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
              if(grid[i][j] == 1){
                  q.push({i, j});
                  fireTime[i][j] = 0;
              }
          }
        }
   
            while(!q.empty()){
                auto t = q.front();
                int x = t.first, y = t.second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int a = x + dir[k][0], b = y + dir[k][1];
                  if(a < 0 || b < 0 || a >= n || b >= m || grid[a][b] == 2) continue;
                       if(fireTime[a][b] > fireTime[x][y] + 1){
                           fireTime[a][b] = 1 + fireTime[x][y];
                           q.push({a, b});
                       }            
                    
                }
            }
            
        }
    int minTime(int wait, vector<vector<int>> &grid, int &n, int &m){
        for(int i = 0; i < n; i++){
            for(int j= 0; j < m; j++){
                dis[i][j] = inf;
             }
        }
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        dis[0][0] = wait;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int x = t.first;
            int y = t.second;
            for(int k = 0; k < 4; k++){
                int a = x + dir[k][0], b = y + dir[k][1];
                if(a < 0 || b < 0 || a >= n || b >= m || grid[a][b] == 2) continue;
                int tempMin = min(dis[a][b], 1 + dis[x][y]);
                if(a == n-1 and b == m-1 and tempMin <= fireTime[a][b]) return tempMin;
               if(tempMin >= fireTime[a][b]) continue;       
                if(dis[a][b] > 1 + dis[x][y]){
                    dis[a][b] = 1 + dis[x][y];
                    q.push({a, b});
                }
            }
        }
        return inf;
    }
    
    int findExtraTime(vector<vector<int>> &grid, int &n, int &m){
        
        if(fireTime[n-1][m-1] == inf){
            return minTime(0, grid, n, m) < inf ? 1e9 : -1;
        }
        int low = 0, high = n*m + 1;
        int mxWait = n*m + 1, ans = -1; 
        while(low <= high){
            int mid = low + (high - low)/2;
            int t = minTime(mid, grid, n, m);
    
            if(t <= fireTime[n-1][m-1]){
                ans = mid;
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
 
        return ans == mxWait ? 1e9 : ans;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dis.clear();
        fireTime.clear();
        dis.resize(n, vector<int>(m, inf));
        fireTime.resize(n, vector<int>(m, inf));
        spreadFire(grid, n, m);
        return findExtraTime(grid, n, m);
    
    }
};