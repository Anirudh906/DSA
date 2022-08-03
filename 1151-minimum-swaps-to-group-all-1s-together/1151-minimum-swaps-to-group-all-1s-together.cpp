class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for(int i = 0; i < data.size(); i++){
            if(data[i]) ones++;
        }
        for(int i = 1; i < data.size(); i++){
            data[i] += data[i-1];
        }
        int mx = 0;
        for(int i = 0; i + ones-1 < data.size(); i++){
            mx = max(mx, data[i+ones-1]- (i-1 >= 0 ? data[i-1]: 0));
        }
        return ones - mx;
    }
};