class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int t) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int res = 0;
        unordered_map<int, int> mp;
        for(int cs = 0; cs < m; cs++){
            for(int ce = cs; ce < m; ce++){
                   mp = {{0, 1}};
                int sum = 0;
                   for(int r = 0; r < n; r++){
                      sum +=  matrix[r][ce] - (cs > 0 ? matrix[r][cs - 1] : 0);  
                    res += mp[sum - t];
                       mp[sum]++;
                   }
            }
        }
        return res;
    }
};