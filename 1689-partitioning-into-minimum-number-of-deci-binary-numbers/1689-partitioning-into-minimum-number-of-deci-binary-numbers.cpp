class Solution {
public:
    int minPartitions(string n) {
        int s = n.length();
        int res = 0;
        for(int i = 0; i < s; i++){
            res = max(res, n[i] - '0');
        }
        return res;
    }
};