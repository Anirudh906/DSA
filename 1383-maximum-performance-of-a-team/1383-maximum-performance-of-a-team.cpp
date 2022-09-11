class Solution {
public:
    int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> vp;
        
        for(int i = 0; i < n; i++){
            vp.push_back({efficiency[i], speed[i]});
        }
        sort(vp.rbegin(), vp.rend());
         priority_queue <int, vector<int>, greater<int> > pq;
        long res = 0, S = 0;
        for(auto pr: vp){
            pq.push(pr.second);
            S += pr.second;
            if(pq.size() > k){
                 
                S -= pq.top();
                pq.pop();
            
            }
            res = max(res, S * pr.first);
       }
        return (int) (res % mod); 
    }
};