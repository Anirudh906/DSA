class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int s, int t) {
        int n = routes.size();
        unordered_map<int, vector<int>> buses;
        for(int i = 0; i < routes.size(); i++){
              for(auto &stop: routes[i]){
                  buses[stop].push_back(i);
              }
        }
        queue<pair<int, int>> q;
        q.push({s, 0});
        unordered_map<int, int> vis;
        vis[s]++;
        while(!q.empty()){
            auto stop = q.front().first;
            auto req = q.front().second;
            q.pop();
           if(stop == t) return req;    
            for(auto &bus: buses[stop]){
                for(int &nxtStop : routes[bus]){
                    if(vis.find(nxtStop) == vis.end()){
                        vis[nxtStop] = 1;
                        q.push({nxtStop, req+1});
                    }
                }
                routes[bus].clear();
            }
        }
        return -1;
    }
};