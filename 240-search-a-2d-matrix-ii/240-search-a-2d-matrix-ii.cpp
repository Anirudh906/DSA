class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int tar) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        
        int c = n - 1, r = 0;
        while(r < m and c >= 0){
            if(matrix[r][c] == tar){
                return true;
            }
            matrix[r][c] > tar ? c-- : r++;
        }
        return false;
    }
};