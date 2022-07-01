class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pr = 0;
        int n = prices.size();
        int mn = prices[0];
        for(int i = 1; i < n; i++){
            mn = min(mn, prices[i - 1]);
            pr = max(pr, max(0, prices[i] - mn));
        }
        return pr;
    }
};