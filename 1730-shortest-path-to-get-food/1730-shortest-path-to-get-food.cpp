class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int getFood(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n == 0 || m == 0) return -1;
        int count = 0;
        queue<pair<int, int>> q;
        int a = 0, b = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '*'){
                    a = i, b = j;
                }
            }
        }
        q.emplace(a, b);
        while(!q.empty()){
            int s = q.size(); count++;
            for(int i = 0; i < s; i++){
            auto t = q.front();
            q.pop();  
            for(int k = 0; k < 4; k++){
                int a = t.first + dir[k][0], b = t.second + dir[k][1];
        if(a >= 0 and a < n and b >= 0 and b < m and grid[a][b] != 'X'){
             if(grid[a][b] == '#') return count;        
             if(grid[a][b] == 'O') {
                 q.emplace(a, b); grid[a][b] = '!';
             }
        }
        }            
        }
            
}
        return -1;
    }
};