class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++){
            mp[convert(strs[i])].push_back(strs[i]);
        }
        for(auto x: mp){
            res.push_back(x.second);
        }
      return res;
    }
    string convert(string &s){
        vector<int> counter(26, 0);
        for(auto c: s){
            counter[c - 'a']++;
        }
        string res = "";
        for(int i = 0; i < 26; i++){
            if(counter[i]) res += string(counter[i], i + 'a');
            }
        
        return res;
    }
};