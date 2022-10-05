class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& p) {
         int n = p.size(), m = p[0].size();
        
         vector<int> r(n), c(m);
         for(int i = 0; i < n; i++){
             for(int j = 0; j < m; j++){
                 r[i] += (p[i][j] == 'B');
             }
         }
         for(int i = 0; i < m; i++){
             for(int j = 0; j < n; j++){
                 c[i] += (p[j][i] == 'B');
             }
         }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(p[i][j] == 'B'){
                    int a = r[i] - 1;
                    int b = c[j] - 1;
                    if(a == 0 and b == 0) ans++;
                }
            }
        }
        return ans;
    }
};