class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
       priority_queue<int> pq;
        int n = stations.size();
        int res = 0; int idx = 0; int cur = startFuel;
        while(cur < target){

        while(idx < n and stations[idx][0] <= cur) pq.push(stations[idx++][1]);
            
            
            if(pq.empty()) return -1;
            cur += pq.top();
            pq.pop();
            
            res++;
       }
        return res;
        
    }
};