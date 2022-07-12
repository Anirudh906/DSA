class Solution {
public:
    void solve(unordered_set<string> & wordDict, vector<string>&ans, string &s, 
    int idx, string temp){
        if(idx >= s.length()) {
            temp = temp.substr(0, temp.length() - 1);
            ans.push_back(temp); return;
        }
        
        for(int j = idx; j < s.length(); j++){
            string t = s.substr(idx, j-idx+1);
           
            if(wordDict.count(t)){
               // cout << t << endl;
                solve(wordDict, ans, s, j+1, temp + t + " ");

            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        
        vector<string> ans;
        unordered_set<string> mp(wordDict.begin(), wordDict.end());
        solve(mp, ans, s, 0, "");
        return ans;
    }
};