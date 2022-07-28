class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0);
        
        
        for(int i = 0; i < s.length(); i++){
            cnt[s[i] - 'a']++;
        }
        
        for(int j = 0; j < t.length(); j++){
            cnt[t[j] - 'a']--;
        }
        
        for(int i = 0; i < 26; i++){
            if(cnt[i] != 0) return false;
        }
        return true;
    }
};