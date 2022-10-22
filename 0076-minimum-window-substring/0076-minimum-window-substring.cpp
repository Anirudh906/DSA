class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int n = s.length();
        for(auto ch: t) mp[ch]++;
        
        int strt = 0, end = 0, idx = INT_MAX, len = INT_MAX;
         int cntr = t.length();
        while(end < n){
            if(mp[s[end]] > 0) cntr--;
            mp[s[end]] --;
            end ++;
            
            while(cntr == 0){
                if(len > end - strt){
                    len = end - strt;
                    idx = strt;
                }
                mp[s[strt]]++;
                if(mp[s[strt]] > 0)cntr++;
                strt++;
                
            }
        }
            return len == INT_MAX ? "" : s.substr(idx, len);
            
        
    }
};

