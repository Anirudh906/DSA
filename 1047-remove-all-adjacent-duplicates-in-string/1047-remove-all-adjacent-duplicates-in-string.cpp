class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            if(!st.empty() and s[i] == st.top()){st.pop(); continue;}
            st.push(s[i]);
        }
        string res = "";
        while(!st.empty()){
                 res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};