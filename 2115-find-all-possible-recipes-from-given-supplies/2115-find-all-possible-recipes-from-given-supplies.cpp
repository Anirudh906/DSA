class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        vector<string> ans;
        unordered_map<string, vector<string>> graph;
        
        unordered_set<string> st;
        for(auto &x: sup) st.insert(x);
        
        unordered_map<string, int> indeg;
        for(auto x:rec) indeg[x] = 0;
        cout << "HERE";
        
        for(int i = 0; i < rec.size(); i++){
            for(int j = 0; j < ing[i].size(); j++){
                if(st.find(ing[i][j]) == st.end()){
                    graph[ing[i][j]].push_back(rec[i]);
                    indeg[rec[i]]++;
                }
            }
        }
        
        
        //KAHN's
        queue<string> q;
        for(auto x: indeg){
            if(x.second == 0){
                q.push(x.first);
            }
        }
        
        
        while(!q.empty()){
        
            auto t = q.front();
                
            q.pop();
            ans.push_back(t);
            for(auto y: graph[t]){
                indeg[y]--;
                if(indeg[y] == 0) q.push(y);
            }
            
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};