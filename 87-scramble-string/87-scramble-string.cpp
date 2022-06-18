class Solution {
public:
    bool checkForScramble(string a, string b, map<string, bool> &mp){
        if(mp.find(a + "," + b) != mp.end()) return mp[a + "," + b];
        
        if(a == b) return true;
        if(a.length() <= 1) return false;
        int s = a.length();
        vector<int> cnt(26);
        for(int i = 0; i < s; i++){
            cnt[a[i] - 'a']++;
            cnt[b[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(cnt[i] != 0) return false;
        }
        
        bool flag = false;
        
        int n = a.length();
        for(int i = 1; i <= n - 1; i++){
if(
    (checkForScramble(a.substr(0, i), b.substr(n - i, i), mp) 
    and 
    checkForScramble(a.substr(i, n - i), b.substr(0, n - i), mp)
     )
   || 
   (checkForScramble(a.substr(0, i), b.substr(0, i), mp) 
    and 
    checkForScramble(a.substr(i, n - i), b.substr(i, n - i), mp)
   )
){
    flag = true;
   }
            }
        return mp[a + "," + b] = flag;
        
    }
    
    bool isScramble(string s1, string s2) {
        map<string, bool> mp;        
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1 != n2) return false;
        return checkForScramble(s1, s2, mp);
    }
};