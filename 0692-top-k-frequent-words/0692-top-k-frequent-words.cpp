class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        vector<pair<string, int>> vp;
        for(auto &x: mp){
            vp.push_back(x);
        }
        sort(vp.begin(), vp.end(), [](auto &a, auto &b){
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
            
        });
       vector<string> res;
        for(int i = 0; i < k; i++){
            res.push_back(vp[i].first);
        }
        return res;
    }
};