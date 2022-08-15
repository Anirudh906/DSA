class Solution {
public:
    int minSteps(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        if(n1 != n2) return -1;
        map<char, int> mp;
        for(int i = 0; i < n1; i++){
            mp[s[i]]++; mp[t[i]]--;
        }
        int ans = 0;
        for(auto &x: mp){
            if(x.second != 0) {
                ans += abs(x.second);
            }
        }
        return ans/2;
    }
};