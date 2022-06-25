class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;    
        int n = tasks.size();
        for(int i = 0; i < n; i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        long time = 0; int i = 0;
      
        priority_queue<pair<long, int>, 
        vector<pair<long, int>>, greater<pair<long,int>>> pq;
        while(i < n || !pq.empty()){
            if(pq.empty()){
                time = max(time, (long)tasks[i][0]);
            }            
            while(i < n and time >= tasks[i][0]){
                pq.push({(long)tasks[i][1], tasks[i][2]});
                i++;
            }
            auto task = pq.top();
            pq.pop();
            time += (long)task.first;
            ans.push_back(task.second);
        }     
    return ans;
    }
};