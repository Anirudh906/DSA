class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(color[i] != 0) continue;
            color[i] = 1;
            q.push(i);
            while(!q.empty()){
                auto t = q.front();
                q.pop();
                
                for(auto &x: graph[t]){
                    if(!color[x]){
                        color[x] = -color[t];
                         q.push(x);
                    }
                   
                    else if(color[x] == color[t]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};