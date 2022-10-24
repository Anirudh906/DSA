class Solution {
public:
    int len = 0;
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        
       check(arr, "", 0);
        return len;
    }
    
    void check(vector<string> &arr, string s, int idx){
         if(!unique(s)) return;
        if(s.size() > len) len = s.size();
        
        for(int i = idx; i < arr.size(); i++){
            check(arr, s + arr[i], i + 1);
        }
    }
    
    bool unique(string &s){
        if(s.length() > 26) return false;
        unordered_set<char> st;
        for(int i =0 ; i < s.length(); i++){
            if(st.find(s[i]) != st.end()) return false;
            st.insert(s[i]);
        }
        return true;
    }
};