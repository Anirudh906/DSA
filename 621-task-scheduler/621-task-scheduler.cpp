class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.size() == 0) return 0;
        vector<int> ch(26);
        for(int i = 0; i < tasks.size(); i++){
            ch[tasks[i] - 'A']++;
        }
        sort(ch.begin(), ch.end());
        
        int mx = ch[25];
        
        int idle = (mx - 1) * n;
        
        for(int i = 24; i >= 0; i--){
            idle -= min(ch[i], mx - 1);
            
        } cout <<idle;
        if(idle < 0) idle = max(0, idle);
        int t = idle  + tasks.size();
        return t;
    }
};