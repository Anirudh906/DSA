class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int truckSize) {
        sort(b.begin(), b.end(), [](auto &a1, auto &b1){
            return a1[1] > b1[1]; 
        });
        int t = truckSize;
        int res = 0;
        for(int i = 0; i < b.size(); i++){
            if(b[i][0] < t) { t -= b[i][0]; res += b[i][1] * b[i][0];}
            else {res += b[i][1]*t; break;}
        }
        return res;
    }
};