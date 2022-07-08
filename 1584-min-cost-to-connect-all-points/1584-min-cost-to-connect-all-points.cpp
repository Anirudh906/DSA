class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>&p) {
      int n = p.size(), res = 0, i = 0, c = 0;
    vector<int> mnd(n, 10000000);
    while (++c < n) {
        mnd[i] = INT_MAX;
        int mnj = i;
        for (int j = 0; j < n; ++j)
            if (mnd[j] != INT_MAX) {
                mnd[j] = min(mnd[j], abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]));
                mnj = mnd[j] < mnd[mnj] ? j : mnj;
            }
        res += mnd[mnj];
        i = mnj;
    }
    return res;   
    }
};