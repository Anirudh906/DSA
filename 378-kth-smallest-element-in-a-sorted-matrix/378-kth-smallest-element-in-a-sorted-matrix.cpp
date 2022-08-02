class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
  int l = matrix[0][0];
        int n = matrix.size();
        int r = matrix[n - 1][n - 1];
        
        while(l <= r){
            int mid = l + (r - l)/ 2;
            int c = 0;
            
            for(int i = 0; i < n; i++){
                vector<int> row = matrix[i];
                c += upper_bound(row.begin(), row.end(), mid) - row.begin();
                
            }
            if(c < k){
                l = mid  + 1;
            }else r = mid - 1;
        }
        
        return l;
        
    }
};