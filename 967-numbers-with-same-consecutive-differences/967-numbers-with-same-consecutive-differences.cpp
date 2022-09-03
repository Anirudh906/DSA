class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
         vector<int> ans = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
         for(int i = 1; i < n; i++){
             vector<int> temp;
             for(auto &x: ans){
                 int y = x % 10;
                 if(y + k < 10){
                     temp.push_back(10*x + y + k);
                 }
                 if(k > 0 and y - k >= 0){
                     temp.push_back(10*x + y - k);
                 }
             }
              ans = temp;
         }
        return ans;
    }
};