class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        else {
            string res = s;
            for(int i = 0; i < s.length(); i++){
                res = min(res, s.substr(i) + s.substr(0, i));
            }
            return res;
        }
    }
};