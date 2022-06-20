class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        set<string> st(words.begin(), words.end());
        for(int i = 0; i < words.size(); i++){
            for(int j = 1; j < words[i].length(); j++){
                st.erase(words[i].substr(j));
            }
        }
        int ans = 0;
        for(auto &s: st){
            ans += s.length() + 1;
        }
        return ans;
    }
};