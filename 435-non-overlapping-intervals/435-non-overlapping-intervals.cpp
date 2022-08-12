class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
          return a[1] < b[1];   
        });
        
        vector<int> prev = intervals[0];
        int ans = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(prev[1] > intervals[i][0]){
                ans++;
            }else prev = intervals[i];
        }
        
        return ans;
    }
};