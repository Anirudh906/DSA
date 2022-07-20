class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> v(26);
        for(int i = 0; i < s.length(); i++) v[s[i] - 'a'].push_back(i);
        
        int ans = 0;
        for(auto &w: words){
          int x = -1;
            bool ok = true;
            for(auto &ch: w){
                auto it = upper_bound(v[ch - 'a'].begin(), v[ch - 'a'].end(), x);
                if(it == v[ch - 'a'].end()) ok = false;
                else x = *it;
            }
            if(ok) ans++;
        }
        return ans;
    }
};