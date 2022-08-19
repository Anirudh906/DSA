class Solution {
public:
    bool Pln(string s){
        string tp = s;
        reverse(tp.begin(), tp.end());
        
        return tp == s;
        
    }
    
    void dfs(string &s, int strt, vector<string> &temp, vector<vector<string>> &res){
        int n = s.length();
        if(strt == n){
               res.push_back(temp);            
        }
        
        for(int i = strt; i < n; i++){
            if(Pln(s.substr(strt, i - strt + 1))){
                temp.push_back(s.substr(strt, i - strt + 1));
                dfs(s, i + 1, temp, res);
                temp.pop_back();
                
            }
        }
        }
  
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        dfs(s, 0, temp, res);
        return res;
    }
};