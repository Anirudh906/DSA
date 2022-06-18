class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<int> next(2, 0), now(2, 0);
        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <=1; buy++){
                if(buy){
                    now[buy] = max(-prices[idx] + next[1 - buy], 
                                      0 + next[buy]);
                }else {
                    now[buy] = max(prices[idx] + next[1-buy],
                                      0 + next[buy]);
                }
                next = now;
            }
        }
        return now[1];
    }
};