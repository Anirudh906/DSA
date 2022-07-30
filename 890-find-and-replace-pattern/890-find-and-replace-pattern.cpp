class Solution {
public:
    string F(string & s){
        unordered_map<char, int> mp;
        string r;
        for(auto c: s) if(!mp.count(c)) mp[c] = mp.size();
        for(int i = 0; i < s.length(); i++) r += 'a' + mp[s[i]];
        return r;
    }
    
    
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
       
        for(auto str: words){

          if(F(str) == F(pattern)) res.push_back(str);
        
        
        }
        return res;
    }
};