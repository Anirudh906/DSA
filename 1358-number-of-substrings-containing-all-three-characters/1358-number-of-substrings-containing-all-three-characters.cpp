class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> cnt(3, 0);
        int n = s.length();
        int strt = 0;
        int res = 0;
        for(int i = 0; i < n; i++){
          cnt[s[i] - 'a']++;
            while(cnt[0] && cnt[1] && cnt[2]){
                --cnt[s[strt++] - 'a'];
                }
            res += strt;
        }
        return res;
    }
};