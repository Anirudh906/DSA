class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        
        sort(points.begin(), points.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        
        int arrowCount = 1;
        int prevEnd = points[0][1];
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] <= prevEnd){
               continue;
            }
                prevEnd = points[i][1];
                arrowCount++;
    
        }
        return arrowCount;
    }
};