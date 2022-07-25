class Solution {
public:
    string minWindow(string s1, string s2) {
        int len = -1, strt = -1;
        int c = 0;
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] == s2[c]){
                c++;
            }
            if(c == s2.size()){
                int d = i;
                while(c > 0){
                    if(s2[c-1] == s1[d]){c--;}
                    d--;
                }
                if(len == -1 || i-d < len){
                    len = i-d;
                    strt = 1+d;
                }
                i = d+1;
            }

        }
        if(len == -1) return "";
        return s1.substr(strt, len);
    }
};