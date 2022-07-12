class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        
        for(auto x : prerequisites){
            adj[x[1]].push_back(x[0]);
            }
       
        vector<int> indeg(n);
        for(int i = 0; i < n; i++){
            for(auto j : adj[i]){
                indeg[j]++;
            }
         }
        queue<int> q;
        
        for(int i = 0; i < n; i++){
           if(indeg[i] == 0) q.push(i);
        }
        int idx = 0;
        vector<int> toporder(n);
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            toporder[idx] = temp; idx++;
            for(auto x : adj[temp]){
                indeg[x]--;
                if(indeg[x] == 0)q.push(x);
            }
        }
        cout << "\nIDX" << idx;
        if(idx == n) return true;
        return false;
        
        
    }
};