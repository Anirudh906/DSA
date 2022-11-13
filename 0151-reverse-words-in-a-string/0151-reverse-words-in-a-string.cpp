class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string temp = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ' and temp != ""){
                v.push_back(temp);
                temp = "";
                continue;
            }
            if(s[i] != ' ') { temp += s[i]; }
        }
           if(temp != "") v.push_back(temp);
            reverse(v.begin(), v.end());
        
        string res = "";
        for(int i = 0; i < v.size(); i++){
            res += v[i];
         if(i != v.size() - 1) res += " ";
        }
        return res;
    }
};