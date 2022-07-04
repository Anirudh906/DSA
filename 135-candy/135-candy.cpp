class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int res = 0;
        vector<int> a(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i]> ratings[i - 1])a[i] = a[i - 1] + 1;
        }
        for(int i = n- 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1])a[i] = max(a[i], a[i + 1] + 1); 
        }
        res = accumulate(a.begin(), a.end(), 0);
        return res;
    }
};