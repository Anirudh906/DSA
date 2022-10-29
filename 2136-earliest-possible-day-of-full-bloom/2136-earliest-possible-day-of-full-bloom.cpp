class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> vp;
        for(int i = 0; i < n; i++){
            vp.push_back({growTime[i], plantTime[i]});
        }
        
        sort(vp.rbegin(), vp.rend());
        
        int cur = 0;
        int tot = 0;
        for(int i = 0; i < n; i++){
            tot = max(tot, cur + vp[i].first + vp[i].second);
            cur += vp[i].second;
        }
        return tot;
    }
};