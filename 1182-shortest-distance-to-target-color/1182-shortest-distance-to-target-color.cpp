class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
     int n = colors.size();
        vector<vector<int>> left(4, vector<int>(n , -1));
        vector<vector<int>> right(4, vector<int>(n, -1));
        
   for(int color = 1; color <= 3; color++){

        if(colors[0] == color){
            left[color][0] = 0;
        }
        for(int i = 1; i < n; i++){
            if(left[color][i - 1] != -1) left[color][i] = left[color][i - 1] + 1;
            if(colors[i] == color)left[color][i] = 0;
        }
    }
        
   for(int color = 1; color <= 3; color++){
            if(colors[n - 1] == color) right[color][n - 1] = 0;
       
          for(int i = n - 2; i >= 0; i--){
              if(right[color][i + 1] != -1) right[color][i] = right[color][i + 1] + 1;
              if(colors[i] == color)right[color][i] = 0;
          }       
        }
        
        vector<int> res;
        
        for(auto q:queries){
            int i = q[0];
            int c = q[1];
            
            int ansx = left[c][i];
            int ansy = right[c][i];
            
            if(ansx == -1 or ansy == -1) res.push_back(max(ansx, ansy));
            else res.push_back(min(ansx, ansy));
            
        }
        return res;
    }
};
