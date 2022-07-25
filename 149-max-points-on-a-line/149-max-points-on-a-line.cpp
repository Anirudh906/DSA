class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for(int i = 0; i < n; i++){
        unordered_map<string, int> mp;
            int dup = 1;
            for(int j = i + 1; j < n; j++){
                if(points[j][0] == points[i][0] and points[j][1] == points[i][1]){
                    dup++;
                }
                else{
                    int dif_x = points[j][0] - points[i][0]; int dif_y = points[j][1] - points[i][1];
                int g = __gcd(dif_x, dif_y);
                    string res = to_string(dif_x / g) + " " + to_string(dif_y / g);
                    mp[res]++;
                    
                }
            }
            ans = max(ans, dup);
            for(auto p: mp){
                ans = max(ans, p.second + dup);
            }
        
        }      return ans;
    }
};

// int n = points.size(), ans = 0;
        // for (int i = 0; i < n; i++) {
        //     unordered_map<string, int> counter;
        //     int dup = 1;
        //     for (int j = i + 1; j < n; j++) {
        //         if (points[j].x == points[i].x && points[j].y == points[i].y) {
        //             dup++;
        //         } else {
        //             int dx = points[j].x - points[i].x, dy = points[j].y - points[i].y, g = gcd(dx, dy);
        //             counter[to_string(dx / g) + '_' + to_string(dy / g)]++;
        //         }
        //     }
        //     ans = max(ans, dup);
        //     for (auto p : counter) {
        //         ans = max(ans, p.second + dup);
        //     }
        // }
        // return ans;