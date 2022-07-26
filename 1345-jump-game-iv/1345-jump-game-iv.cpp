class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, vector<int>> mp;
        
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }
        
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(0);
        visited[0] = true;
        int step = 0;
        while(!q.empty()){
            int s = q.size();
            for(int k = 0; k < s; k++){
                auto i = q.front(); q.pop();
                if(i == n - 1) return step;
                vector<int> &next = mp[arr[i]];
                next.push_back(i - 1);
                next.push_back(i + 1);
                
                for(auto j: next){
                    if(j >= 0 and j < n and !visited[j]){
                        q.push(j);
                        visited[j] = true;
                    }
                }
                next.clear();
            }
            step++;
        }
        return -1;
    }
};